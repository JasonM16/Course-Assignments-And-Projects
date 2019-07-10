using Microsoft.AspNetCore.Identity;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Threading.Tasks;
using CareerWebsite.Models;

namespace CareerWebsite
{
    public static class IdentitySeedData
    {
        public static async Task CreateAdminAccount(IServiceProvider serviceProvider,
            IConfiguration configuration)
        {
            IServiceScopeFactory scopeFactory = serviceProvider.GetRequiredService<IServiceScopeFactory>();

            using (IServiceScope scope = scopeFactory.CreateScope())
            {

                UserManager<ApplicationUser> userManager =
                    scope.ServiceProvider.GetRequiredService<UserManager<ApplicationUser>>();
                RoleManager<IdentityRole> roleManager =
                    scope.ServiceProvider.GetRequiredService<RoleManager<IdentityRole>>();

                string username = configuration["AdminUser:Name"];
                string email = configuration["AdminUser:Email"];
                string password = configuration["AdminUser:Password"];
                string role = configuration["AdminUser:Role"];

                if (await userManager.FindByNameAsync(username) == null)
                {
                    if (await roleManager.FindByNameAsync(role) == null)
                    {
                        await roleManager.CreateAsync(new IdentityRole(role));
                    }

                    ApplicationUser user = new ApplicationUser
                    {
                        UserName = username,
                        Email = email
                    };

                    IdentityResult result = await userManager
                        .CreateAsync(user, password);
                    if (result.Succeeded)
                    {
                        await userManager.AddToRoleAsync(user, role);
                    }
                }
            }
        }
    }
}