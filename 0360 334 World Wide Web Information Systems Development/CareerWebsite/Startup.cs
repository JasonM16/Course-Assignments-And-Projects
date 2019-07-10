using System;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using CareerWebsite.Data;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;
using CareerWebsite.Services;
using Microsoft.AspNetCore.Http;


namespace CareerWebsite
{
    public class Startup
    {
        public Startup(IConfiguration configuration, IHostingEnvironment hostingEnvironment)
        {
            Configuration = configuration;
            _configurationRoot = new ConfigurationBuilder()
                .SetBasePath(hostingEnvironment.ContentRootPath)
                //.AddJsonFile("appsettings.json")
                .AddJsonFile($"appsettings.{hostingEnvironment.EnvironmentName}.json", true)
                .Build();
        }

        private IConfigurationRoot _configurationRoot;
        public IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddDbContext<ApplicationDbContext>(options =>
                options.UseSqlServer(Configuration.GetConnectionString("DefaultConnection")));


            services.AddTransient<ICandidateRepository, CandidateRepository>();
            services.AddTransient<IJobRepository, JobRepository>();
            services.AddTransient<IEmployerRepository, EmployerRepository>();
            services.AddSingleton<IHttpContextAccessor, HttpContextAccessor>();
            

            services.AddIdentity<ApplicationUser, IdentityRole>(opts => {
                    opts.User.RequireUniqueEmail = false;
                    opts.Password.RequiredLength = 6;
                    opts.Password.RequireNonAlphanumeric = false;
                    opts.Password.RequireLowercase = false;
                    opts.Password.RequireUppercase = false;
                    opts.Password.RequireDigit = false;
                })
                .AddEntityFrameworkStores<ApplicationDbContext>()
                .AddDefaultTokenProviders();
           
            // Add application services.           
            services.AddTransient<IEmailSender, EmailSender>();            
            services.AddMemoryCache();
            services.AddMvc();                   
            services.AddSession();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IHostingEnvironment env, IServiceProvider service)
        {
            if (env.IsDevelopment())
            {
                app.UseBrowserLink();
                app.UseDeveloperExceptionPage();
                app.UseDatabaseErrorPage();
            }
            else
            {
                app.UseExceptionHandler("/Home/Error");
            }

            app.UseStaticFiles();
            app.UseSession();
            app.UseAuthentication();
            

            app.UseMvc(routes =>
            {
                routes.MapRoute(
                    name: "default",
                    template: "{controller=Home}/{action=Index}/{id?}");
            });

            IdentitySeedData.CreateAdminAccount(app.ApplicationServices, Configuration).Wait();
            DbInitializer.ConfigureUsers(app, app.ApplicationServices, Configuration);
        }
    }
}
