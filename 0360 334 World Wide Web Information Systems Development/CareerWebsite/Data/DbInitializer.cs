using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using CareerWebsite.Models;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Identity;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;

namespace CareerWebsite.Data
{
    public static class DbInitializer
    {
        public static void SeedData(IApplicationBuilder ab, UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> roleManager)
        {
            using (var serviceScope = ab.ApplicationServices.CreateScope())
            {
                using (var context = serviceScope.ServiceProvider.GetRequiredService<ApplicationDbContext>())
                {
                    AddRoles(userManager, roleManager);
                    SeedJobTypes(context);
                    SeedCategories(context);
                    SeedEducation(context);
                    SeedProvinces(context);
                    SeedEmployers(context, userManager, roleManager);
                    SeedCandidates(context, userManager, roleManager);
                }
            }
        }

        public static void ConfigureUsers(IApplicationBuilder ab, IServiceProvider serviceProvider, IConfiguration configuration)
        {
            IServiceScopeFactory scopeFactory = serviceProvider.GetRequiredService<IServiceScopeFactory>();

            using (IServiceScope scope = scopeFactory.CreateScope())
            {
                UserManager<ApplicationUser> userManager =
                    scope.ServiceProvider.GetRequiredService<UserManager<ApplicationUser>>();
                RoleManager<IdentityRole> roleManager =
                    scope.ServiceProvider.GetRequiredService<RoleManager<IdentityRole>>();

                SeedData(ab, userManager, roleManager);
            }
        }

        private static void AddRoles(UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> roleManager)
        {
            string[] roles = { "Admin", "Employer", "Candidate" };

            foreach (var role in roles)
                if (roleManager.FindByNameAsync(role).Result == null)
                    roleManager.CreateAsync(new IdentityRole(role)).Wait();           
        }

        #region JOBTYPES
        private static void SeedJobTypes(ApplicationDbContext context)
        {
            if (context.JobTypes.Any()) return;
            
            context.JobTypes.AddRange(
                new List<JobType>
                {
                    new JobType { Name = "Full Time"},
                    new JobType { Name = "Part Time"},
                    new JobType { Name = "Volunteer"},
                    new JobType { Name = "Co-op"},
                    new JobType { Name = "Contract"},
                    new JobType { Name = "Seasonal"},
                });

            context.SaveChanges();
        }
        #endregion

        #region EDUCATION
        private static void SeedEducation(ApplicationDbContext context)
        {
            if (context.Education.Any()) return;

            context.Education.AddRange(
                new List<Education>
                {   
                    new Education { Name = "Masters Degree" },
                    new Education { Name = "Ph.D/Postdoc" },
                    new Education { Name = "Bachelor's Degree" },
                    new Education { Name = "College Diploma" },
                    new Education { Name = "High School" },
                    new Education { Name = "Some College/Some University" },
                
                });

            context.SaveChanges();

        }
        #endregion 

        #region PROVINCES
        private static void SeedProvinces(ApplicationDbContext context)
        {
            if(context.Provinces.Any()) return;

            context.Provinces.AddRange(
                new List<Province>()
                {
                    new Province { Name = "Alberta", ShortName = "AB" },
                    new Province { Name = "British Columbia", ShortName = "BC" },
                    new Province { Name = "Manitoba", ShortName = "MB" },
                    new Province { Name = "New Brunswick", ShortName = "NB" },
                    new Province { Name = "Newfoundland And Labrador", ShortName = "NL" },
                    new Province { Name = "Northwest Territories", ShortName = "NT" },
                    new Province { Name = "Nova Scotia", ShortName = "NS" },
                    new Province { Name = "Nunavut", ShortName = "NU" },
                    new Province { Name = "Ontario", ShortName = "ON" },
                    new Province { Name = "Prince Edward Island", ShortName = "PE" },
                    new Province { Name = "Quebec", ShortName = "QC" },
                    new Province { Name = "Saskatchewan", ShortName = "SK" },
                    new Province { Name = "Yukon", ShortName = "YT" },
                });

            context.SaveChanges();
        }
        #endregion

        #region CATEGORIES
        private static void SeedCategories(ApplicationDbContext context)
        {
            if(context.Categories.Any()) return;

            foreach (JobCategoryList item in (JobCategoryList[]) Enum.GetValues(typeof(JobCategoryList)))
                context.Add(new Category{Name = item.GetDisplayName()});            

            context.SaveChanges();
        }
        #endregion
        
        #region JOBS
        private static void SeedJobs(ApplicationDbContext context)
        {
            if (context.Jobs.Any()) return;

            context.Jobs.AddRange(
                new List<Job>
                {
                    new Job()
                    {


                    },

                    new Job()
                    {


                    },
                    new Job()
                    {


                    },
                    new Job()
                    {


                    },
                    new Job()
                    {


                    },
                    new Job()
                    {


                    },
                    new Job()
                    {


                    },
                });

            context.SaveChanges();
        }
        #endregion

        #region EMPLOYERS
        private static void SeedEmployers(ApplicationDbContext context, UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> role)
        {
            if (context.Employers.Any()) return;

            var employers = new List<Employer>
            {
                 new Employer
            {
                Name = "Beacon Hall Golf Club",
                UserName = "BeaconHallGolfClub",
                Email = "careers@BeaconHallGolfClub.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Dishwasher/Prep Cook",
                        Salary = 12000m,
                        NoOfVacancies = 2,
                        JobLocation = new Location {City = "Aurora", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(65),
                        Start_Date = DateTime.Today.AddDays(91),
                        JobDescription = "Dishwasher/kitchen help needed in fast paced private golf club Seeking team player with good work ethic and enthusiasm. Good attitude, interpersonal and communicative skills are a MUST. Need to provide own transportation. Position available from May to mid-November. ",
                        MinEducationId = 5, 
                        JobTypeId = 2,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Food_Service),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Proper washing of dishes, utensils, tools as required by kitchen chef."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Sweeping & mopping"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Food prep if needed (dependent on skill level)"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Dry storage and walk-in refrigerator organization and sanitation."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Sutherland",
                UserName = "Sutherland",
                Email = "careers@Sutherland.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Technical Support Specialist",
                        Salary = 45000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Sault Ste. Marie", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(25),
                        Start_Date = DateTime.Today.AddDays(50),
                        JobDescription = "Sutherland is seeking a motivated and passionate person to join us as a Senior Technical Consultant.As a Senior Technical Consultant you will be answering inbound calls to provide exceptional customer service to consumers. This could include responding to inquiries about products and services, processing payments, or performing general account maintenance. In addition, up-selling customers to new products or services is expected and encouraged.",
                        MinEducationId = 5, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Insurance),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "High school diploma or GED "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Demonstrated ability to perform at a high level, to support our high volume of inbound calls "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent verbal and written communication skills; proficient reading skills required "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Multi-tasking skills, showcased through the use of several applications; experience working with CRM applications preferred "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Basic PC keyboarding skills; basic Microsoft Office (Outlook, Word, Excel) experience required "
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "All-Risks Insurance Brokers Limited",
                UserName = "All-RisksInsuranceBrokersLimited",
                Email = "careers@arib.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Data Processor",
                        Salary = 30000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Windsor", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "All-Risks Insurance Brokers Limited is a full service insurance brokerage offering a broad array of property, casualty, life, health and investment products and services to the residents of Ontario. We offer our customers a choice of high quality insurance products from a number of reputable and financially secure insurance companies in a friendly and courteous environment.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Insurance),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "RIBO License mandatory (minimum 2 years experience)"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Minimum of 2-3 years in an similar role"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Sig XP experience an asset"
                            },
                             new Qualification
                            {
                                QualificationDetails = "Experience with Microsoft Suite (Word, Excel, Outlook, PowerPoint)"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience working on insurance company portals"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Ability to work independently as well as with a team"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Strong attention to detail"
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Ability to organize and prioritize work effectively"
                            },
                              new Qualification 
                            {
                                QualificationDetails = "Excellent oral and written communications skills"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Government of Canada",
                UserName = "GovernmentofCanada",
                Email = "jobs@GovernmentofCanada",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Surveillance Pilot Inventory",
                        Salary = 98349m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Ottawa", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(15),
                        Start_Date = DateTime.Today.AddDays(75),
                        JobDescription = "When you apply to this selection process, you are not applying for a specific job, but to an inventory for future vacancies. As positions become available, applicants who meet the qualifications may be contacted for further assessment. Fueled by a dedicated workforce, Transport Canada’s Aircraft Services Directorate is seeking Surveillance Pilots who are dedicated, growth-oriented and enjoy working as part of a team. This position is located at our headquarters, in the Aircraft Services' hangar at Ottawa Macdonald-Cartier International Airport.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Government),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "A secondary school diploma or an acceptable combination of education, training and/or experience."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Possession of a valid Canadian Airline Transportation Pilot License Aeroplane Category with a Group 1 Instrument Rating"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Possession of a valid Restricted Radio-Telephone Operator Certificate (endorsed aeronautical)."
                            },
                            new Qualification
                            {
                                QualificationDetails = "A minimum of 3,000 hours of flight time on multi-engine turbine powered airplanes"
                            },
                            new Qualification 
                            {
                                QualificationDetails = " A minimum of 500 hours as a pilot in command of multi-engine turbine powered airplanes."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "A minimum of 300 hours instrument flight time (150 hours must be actual)."
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Recent* experience as flight crew in operations in the Canadian Arctic."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience with deployments and remote operations away from a main base for extended periods of at least one week."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Gatestone & Co",
                UserName = "Gatestone",
                Email = "careers@Gatestone.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Helpdesk Technician",
                        Salary = 37500m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Brantford", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(25),
                        Start_Date = DateTime.Today.AddDays(55),
                        JobDescription = "This position will be responsible for providing technical support within the company and is required to work the following shifts on a rotating basis, as well as providing on-call coverage. These hours and shifts are subject to change.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Answering, prioritizing, and responding to incoming telephone, tickets, and e-mail requests for assistance from users experiencing problems with hardware, software, networking, and other computer-related technologies as well as all telecommunications issues"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Assist with some facilities tasks (checking lights, Doors, ensuring vending machines are working) and notifying the concern vendors"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Assure that all tickets requiring follow up work and/or calls receive appropriate attention"
                            },
                            new Qualification
                            {
                                QualificationDetails = "An analytical thinker, ability to synthesize complex or diverse information, collect and research data, use intuition and experience to complement data, design work flows and procedures"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Proven ability to work within stringent timeframe"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Able to lift and palletize heavy equipment. (PC’s, monitors, printers.)"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Proficient with IOS and Android"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Knowledge of AS400"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Efficient with troubleshooting software and hardware problems"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Prodigy Game",
                UserName = "ProdigyGame",
                Email = "jobs@ProdigyGame.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Game QA",
                        Salary = 65000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Montréal", ProvinceId = 11, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "In the last 5 years, Prodigy has gone from 3,000 to over 30,000,000 students across North America (including 80% of all Ontario students), and is currently the fastest growing educational startup in North America. By joining our team, you will have the opportunity to help an entire generation of students to LOVE learning while working alongside some of the brightest and most passionate people in education and gaming.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "1 Year of QA Experience."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "In-depth knowledge and passion for a wide variety of video game titles."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Innate desire to understand how things work, to dig deeper and continue to learn."
                            },
                             new Qualification 
                            {
                                QualificationDetails = "A strong focus on professional growth."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Familiarity with bug tracking and test tracking software, preferably JIRA & TestRail."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Moxie's",
                UserName = "Moxies",
                Email = "jobs@Moxies.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Technician",
                        Salary = 55650m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Calgary", ProvinceId = 1, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(23),
                        Start_Date = DateTime.Today.AddDays(55),
                        JobDescription = "We are looking for a service-oriented, hospitable and energetic IT Technician to join our corporate home office team in Calgary, AB. You will be the first level of support; delivering technical assistance and support for incoming emails, calls and queries related to Moxie's Corporate computer systems, software and hardware. The successful candidate will report directly to Director of IT. ",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "An organized, detail oriented and motivated person "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent documentation and communication skills "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Someone who can work flexible hours and travel when needed and can provide on call after hours support on a rotational schedule "
                            },
                            new Qualification
                            {
                                QualificationDetails = "You have proven troubleshooting skills and can work with customers through to completion "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Hands-on experience with managing and troubleshooting MS Windows 7, 8.1, & 10 "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Hands-on experience managing Windows PCs "
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Strong working knowledge of the Microsoft Suite of applications "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Fundamental understanding of physical networks and topology"
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Experience with managing and Troubleshooting iOS MDM "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "MS Exchange account management "
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Government of Canada",
                UserName = "GovernmentofCanada",
                Email = "job@GovernmentofCanada.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Technician Inventory",
                        Salary = 0m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Vancouver", ProvinceId = 2, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "As an IM/IT Technician, you will be responsible for: Plans and performs the installation, configuration, testing, quality assurance and maintenance of computer hardware and software, related auxiliary equipment and assists in the support of network servers and corporate databases",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Provides basic network administration and maintenance, security, inventory, technical support services for problem resolution services for computers and for interconnectivity issues for computer network components and remote access communications."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Provides advice and input to recommendations to management and staff regarding the purchase and installation of new hardware and software to optimize the use of IT systems and improve client service delivery."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Prepares documentation and provides advice, guidance, coaching and training to staff and clients on the use of computers, peripherals, applications and platform software."
                            },
                            new Qualification
                            {
                                QualificationDetails = "Performs operational programming from specifications, writes utilities such as macros, batch files or templates/forms, maintains change control procedures and captures and inputs data to provide information to clients."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Generates and analyzes data and produces reports, user guides and statistical information regarding hardware/software inventory, locations and sign outs."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Maintains a program of continuing study of trends and developments in all aspects of information technology advancements."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "zedIT Solutions",
                UserName = "zedITSolutions",
                Email = "careers@zedITSolutions.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Application Analyst",
                        Salary = 48500m,
                        NoOfVacancies = 4,
                        JobLocation = new Location {City = "St. John's", ProvinceId = 5, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(15),
                        Start_Date = DateTime.Today.AddDays(25),
                        JobDescription = "Group zed ( www.gzed.com ) is a leading IT Professional Services Consultancy with more than 20 years of dedicated industry experience working with public and private sector clients throughout North America and the world. We provide a full range of industry leading core competencies, which focus on helping clients measurably achieve their business and technology objectives. By integrating strategic consulting with solution delivery, our customers benefit from having a single partner for defining strategies, executing razor-sharp solutions and delivering results. ",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "At least 2 years’ experience in an IT Application or Reporting Analyst role"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Proven experience with writing custom reports and queries in a Microsoft SQL Server database environment"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience with ticket management systems, including Zendesk"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Proven ability to work with business users to identify and document business problems, and recommending technology or business process changes to solve business problems"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Ability to work independently while supporting remote teams"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Flexibility and adaptability to be responsive to support requests while balancing daily tasks and responsibilities"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Degree or College Diploma from a recognized post-secondary institution"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Dovico ",
                UserName = "Dovico ",
                Email = "careers@Dovico .com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Entry Level IT Job",
                        Salary = 42000m,
                        NoOfVacancies = 2,
                        JobLocation = new Location {City = "Moncton", ProvinceId = 4, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "It’s the people who make the difference at Dovico. Growing strong for the last 25 years, our commitment to quality is but the tip of the iceberg. We’re looking for someone who enjoys continuous learning and loves using leading-edge technologies and tools, a person who has a passion for quality and won’t settle for anything less. Someone who wants to help us build world-class products for our World Class Customers. ",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "An IT diploma from an accredited college or university"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "A minimum of one year of experience in the IT industry is a must"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Technical knowledge of some or all of the following technologies: Microsoft Windows OS, Apple "
                            },
                             new Qualification
                            {
                                QualificationDetails = "MacOS, Microsoft Office 365, mobile technologies, email technologies, SQL Server, Windows Server OS, Linux OS, TCP/IP, DNS, SMTP"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent troubleshooting skills and the ability to identify root causes"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience in scripting languages including bash, python, ruby, or PowerShell"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience with AWS or Azure cloud environments an asset "
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Astaldi Canada",
                UserName = "AstaldiCanada",
                Email = "careers@AstaldiCanada.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Technician",
                        Salary = 32000m,
                        NoOfVacancies = 3,
                        JobLocation = new Location {City = "Goose Bay", ProvinceId = 5, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(105),
                        Start_Date = DateTime.Today.AddDays(195),
                        JobDescription = "Reporting to the IT Manager, the IT Technician is responsible for supporting computers, phones and other software and IT related equipment for over 200 users on a construction site in remote Labrador",
                        MinEducationId = 4, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Minimum 3 to 5 years of experience in a related position"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Previous experience working on a Construction Project on a remote work site would be considered an asset"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Cisco switches, routers and VOIP Telephone experience would be considered an asset"
                            },
                            new Qualification
                            {
                                QualificationDetails = "VM Ware experience"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Cisco and / or Microsoft Certifications would be considered an asset"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "MSSQL , SSRS knowledge would be considered an asset"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Programming background (Web development, PHP, .Net) would be considered an asset"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "SharePoint would be considered an asset"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Must possess skills related to problem solving, quick reactions and adaptability as priorities often change"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Cummins Inc.",
                UserName = "Cummins",
                Email = "jobs@Cummins.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Engine Field Service Technician",
                        Salary = 365000m,
                        NoOfVacancies = 5,
                        JobLocation = new Location {City = "Val-d'Or", ProvinceId = 11, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(55),
                        Start_Date = DateTime.Today.AddDays(90),
                        JobDescription = "Technical specialist and primary customer support contact to diagnose and execute complex repairs to engine products at the customer’s site. Establishes and continually develops productive customer relations and ensures prompt and efficient attention to customer needs. Applies the use of specialized tools and follows documented procedures and policies to diagnose and complete complex repairs at customer site. Performs preventative maintenance activities as per documented schedules and standards on engines and related components in the field. ",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Ability to train Service Personnel to develop their diagnostic skills "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Able to identify opportunities for work process improvements and recommend appropriate action"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Able to understand and follow the Technical Support Request ((TSR) process "
                            },
                            new Qualification
                            {
                                QualificationDetails = "Apprentice Trained Engine Technician (Preferred) "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Vocational diploma from relevant technical institution "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Expert level knowledge of and/or experience with engine products "
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Thames Valley District School Board",
                UserName = "TVDSB",
                Email = "careers@TVDSB.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Technical Support Analyst",
                        Salary = 45000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "London", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "Working in a team atmosphere, and reporting to the Service Desk Coordinator or Specialized Technology Coordinator, the Technical Support Analyst will utilize the Service Desk system in providing remote and on- site technical support to the users. The Technical Support Analyst will install, configure, monitor and troubleshoot software, computer hardware, peripherals and training equipment.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "The successful candidate will have minimum two (2) years work related experience diagnosing problems, supporting computers, users, and computer networks. "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent customer service skills, experience with assistive technology, and experience working on a Service desk would be an asset."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "The successful candidate will be a graduate of a recognized two year post-secondary program in computer technologies or equivalent."
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Expertise is required in contemporary and legacy versions of Microsoft Windows Operating Systems, iOS, Chrome OS, Android, MDM, and System Center Configuration Manager. Access to a reliable vehicle and a valid driver’s licence are required."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "WIKA Instruments Ltd",
                UserName = "WIKAInstruments",
                Email = "jobs@wika.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Technical Support/Data Analyst",
                        Salary = 62000m,
                        NoOfVacancies = 3,
                        JobLocation = new Location {City = "Edmonton", ProvinceId = 1, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(15),
                        Start_Date = DateTime.Today.AddDays(35),
                        JobDescription = "Under the supervision of the IT Manager the Technical Support/ Data Analyst will provide technical assistance and training to internal customers.",
                        MinEducationId = 4, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Two year certificate from college or technical school, or one to two years related experience"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Able to work independently and efficiently to meet deadlines"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Able to promptly answer support related issues"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Self motivated, detail-oriented and organized"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience with hardware and software such as Windows server, Microsoft Office, Exchange, Active Directory, Microsoft Axapta"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent communication (oral and written), interpersonal, organizational skills"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Orkin Canada",
                UserName = "Orkin",
                Email = "careers@Orkin.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Pest Control Service Technician",
                        Salary = 60000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Fraser Valley Regional District", ProvinceId = 2, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(20),
                        Start_Date = DateTime.Today.AddDays(50),
                        JobDescription = "ORKIN Canada provides pest prevention and elimination services for our local and national clients. With more than a century of experience, our shared knowledge and resources are available to the benefit of our team and customers. As pest management professionals, we provide pest free environments for our valued residential, commercial, industrial, and public sector customers.",
                        MinEducationId = 5, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Sales),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Inspect interior/exterior areas of structures to assess conditions conducive to pest infestation."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Advise clients regarding treatment strategy and precautions, recommend preventative measures."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Maintain a high level of customer satisfaction that generates referrals and retains customers."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Best Buy Canada",
                UserName = "BestBuyCanada",
                Email = "careers@BestBuyCanada.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Geek Squad Technical Support",
                        Salary = 40000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Yukon", ProvinceId = 13, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(145),
                        Start_Date = DateTime.Today.AddDays(195),
                        JobDescription = "As a Geek Squad Remote Repair Agent, you goal is to fix, solve, or enhance your client’s technology. Whether they’re connecting because a virus has taken over their laptop - or they need help installing their favourite game - your goal is to ensure they leave with a smile on their face. ",
                        MinEducationId = 5, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Utilize great customer service skills to facilitate the complete solution of product repair, upgrades, installations and other services using an online portal and remote desktop software"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Advise clients on the proper and optimal use of their products"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Act as a single point of contact for the client. If they need to schedule an in-home service call, let’s book them in!"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Identify and recommend additional solutions to the client"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Maintain certain minimum KPI’s. That’s how we best serve our clients"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Attend in-store meetings or trainings, as required"
                            },
                             new Qualification 
                            {
                                QualificationDetails = "A+ Certified preferred"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Global Payments Canada ",
                UserName = "GlobalPaymentsCanada",
                Email = "jobs@GlobalPaymentsCanada.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Service Technician",
                        Salary = 45750m,
                        NoOfVacancies = 7,
                        JobLocation = new Location {City = "Vancouver", ProvinceId = 2, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(75),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "The Field Service Representative (FSR)is accountable for installation and training on standalone/integrated products both on-site and via telephone (primarily for Major and National accounts). The FSR will also participate in new or enhanced product pilots under the guidance of the Product Manager. As well, the FSR will respond to escalated incidents across the merchant base. The FSR will also provide operational support to Third Party Service providers.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)(JobCategoryList.Information_Technology),
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Post Secondary education in computer related studies"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "2-4 years experience with POS hardware"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Competency in troubleshooting hardware failures and communication connections both Dial, Datapac3201, and IP"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Working knowledge of POS terminal management systems, Tracker, MOSS applications, and Microsoft Office."
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Available to work outside normal working hours depending on requirements"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "French is a asset"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Thompson Rivers University",
                UserName = "ThompsonRiversUniversity",
                Email = "careers@ThompsonRiversUniversity.edu",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Service Desk Analyst",
                        Salary = 50000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Kamloops", ProvinceId = 2, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "Reporting to the Supervisor, IT Service Desk, this position is IT Services single point of contact for students, staff and faculty that require IT support. The primary modes of contact are by telephone, email and face-to-face. As the first point of contact, IT Service Desk Analysts often recognize when a major IT issue has occurred and escalate those concerns to management.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Information_Technology,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Experience working at a call centre or help desk with ACD where the daily, ongoing, primary function was responding to customer contact requests"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience in a fast-paced environment where exceptional service and customer satisfaction is a key element"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience in face-to-face technical support or sales"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Government of Canada",
                UserName = "GovernmentCanada",
                Email = "careers@GovernmentCanada.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "Telecommunications Operator Trainee",
                        Salary = 64864m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Iqaluit", ProvinceId = 8, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(85),
                        Start_Date = DateTime.Today.AddDays(125),
                        JobDescription = "A Telecommunications Operator is responsible for responding to both Police and Emergency 911 calls for service while dispatching RCMP and other emergency responders to incidents in their respective province. This requires a level of multi-tasking simultaneously on a computer with multiple screens/programs while responding to calls on a radio/phone of which some may be highly stressful \"life or death\" situations. Telecommunications Operators are often exposed to emotionally charged clients and incidents which may be traumatic, violent and disturbing. Telecommunication Operators work shift work (24 hours a day, 7 days a week and 365 days a year).",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Government,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Successful completion of a Telecommunications Operator Training Program recognized by the Royal Canadian Mounted Police (RCMP)"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Ability to type/keyboard at 43 net w.p.m. with less than 5% error rate"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Meets and maintains the medical profile standards established for the position."
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "SHIL Infotech Inc",
                UserName = "SHILInfotech",
                Email = "jobs@SHILInfotech.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT (information technology) consultant",
                        Salary = 58950m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Regina", ProvinceId = 12, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(85),
                        Start_Date = DateTime.Today.AddDays(135),
                        JobDescription = "Confer with clients to identify and document requirements; Conduct business and technical studies; Design, develop and implement information systems business solutions; Provide advice on information systems strategy, policy, management and service delivery; Assess physical and technical security risks to data, software and hardware; Develop and implement policies and procedures throughout the software development life cycle; Develop policies, procedures and contingency plans to minimize the effects of security breaches; Conduct reviews to assess quality assurance practices, software products and information systems",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Information_Technology,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Operating Systems and Software"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Virtualization"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Microsoft Visual Studio"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Hyperion"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Programming Languages"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Own transportation"
                            },
                            new Qualification
                            {
                                QualificationDetails = "Word processing software; Spreadsheet; Linux; Database software; C; C++; JavaOS; "
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Software development; SQL; MS Office; Business diagram software"
                            },                            
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Corporate Renaissance Group",
                UserName = "CorporateRenaissanceGroup",
                Email = "jobs@CorporateRenaissanceGroup.ca",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Consultant",
                        Salary = 70000m,
                        NoOfVacancies = 2,
                        JobLocation = new Location {City = "Nepean", ProvinceId = 9, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(45),
                        Start_Date = DateTime.Today.AddDays(95),
                        JobDescription = "Design, develop and implement information systems business solutions",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Information_Technology,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "Database software; SQL; SharePoint"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Effective interpersonal skills"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Excellent written communication"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "FLS Transportation Services",
                UserName = "FLSTransportationServices",
                Email = "jobs@flsts.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Technician- Helpdesk II",
                        Salary = 48000m,
                        NoOfVacancies = 1,
                        JobLocation = new Location {City = "Montreal", ProvinceId = 11, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(25),
                        Start_Date = DateTime.Today.AddDays(85),
                        JobDescription = "FLS Transportation is looking for a qualified IT Technician that will install and maintain computer systems and networks aiming for the highest functionality. You will also “train” users of the systems to make appropriate and safe usage of the IT infrastructure.",
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Information_Technology,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "In depth understanding of diverse computer systems and networks"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Certification as IT Technician will be an advantage (e.g. CompTIA A+, Microsoft Certified IT Professional)"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Experience with SQL would be a strong asset"
                            },
                        }
                    }
                }
            },
            new Employer
            {
                Name = "Singleton Urquhart",
                UserName = "SingletonUrquhart",
                Email = "careers@SingletonUrquhart.com",
                Jobs = new List<Job>
                {
                    new Job
                    {
                        Title = "IT Help Desk Technician",
                        Salary = 55000m,
                        NoOfVacancies = 2,
                        JobLocation = new Location {City = "Vancouver", ProvinceId = 2, PostalCode = "M5A 4T3"},
                        Date_Posted = DateTime.Today,
                        Closing_Date = DateTime.Today.AddDays(65),
                        Start_Date = DateTime.Today.AddDays(145),
                        JobDescription = "Singleton Reynolds is seeking two experienced IT Help Desk Technicians to join our IT Department. The successful candidates must have a minimum of 3-5 years' experience in a desktop support role (law firm experience would be an asset) with exposure to the backend.", 
                        MinEducationId = 3, // Bachelor
                        JobTypeId = 1,      // Full-time   
                        CategoryId = (int)JobCategoryList.Information_Technology,
                        Qualifications = new List<Qualification>
                        {
                            new Qualification
                            {
                                QualificationDetails = "3 years of relevant technical experience"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Working knowledge of iManage document management system"
                            },
                            new Qualification 
                            {
                                QualificationDetails = "Advanced knowledge of Windows Server 2008, 2012, and 2016 (Active Directory, Group Policy, DNS, and DHCP)"
                            },
                             new Qualification 
                            {
                                QualificationDetails = "Networking knowledge (CCNA certification desired), particularly in regards to Meraki "
                            },
                              new Qualification 
                            {
                                QualificationDetails = "Desired familiarity with dictation/transcription software, Adobe Acrobat Standard, NOD32 Antivirus."
                            },
                        }
                    }
                }
            },         
                new Employer
                {
                    Name = "IBM",
                    UserName = "IBM",
                    Email = "employer@IBM.com",
                    Rating = 0m,
                    Reviews = new List<EmployerReview>
                    {
                        new EmployerReview
                        {
                            Review = 3.0m,
                            Details =
                                "It\'s a great place to work. There are often times when we need to stretch working hours but it\'s not too hectic. The only issue is with advancing to the next level."
                        },
                        new EmployerReview
                        {
                            Review = 5.0m,
                            Details =
                                "IBM as a whole cannot be judged based on a single team. The team I worked on was fantastic. They gave me tasks that were challenging and allowed me to experiment and learn while taking the time to look and build strong solutions. There was no unfair pressure from management and the environment was inclusive and comfortable.This was an internship so my experience is limited."
                        }
                    },
                    Jobs = new List<Job>
                    {
                        new Job
                        {
                            Title = "Junior Software Developer",
                            Salary = 80_000.00m,
                            NoOfVacancies = 2,
                            JobLocation = new Location {City = "Toronto", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(45),
                            Start_Date = DateTime.Today.AddDays(95),
                            JobDescription =
                                "We live in a moment of remarkable change and opportunity. Data and Analytics are transforming industries, society, and even the workplace–by creating professions that didn\'t exist before the emergence of data, cloud, social, and mobile. Cognitive computing is creating new customer experiences, reinventing operations and transforming industries by creating systems that can understand, reason and learn. As the largest technology employer in the world, IBM is a leader in this global transformation and just the place to develop your career.\r\n\r\nWe’re looking for candidates to work alongside a multidisciplinary team of developers, designers, data scientists and business professionals.\r\n\r\nThe ideal candidate must have strong technical skills and a passion for software development. They must collaborate in a high energy environment and exhibit creative thinking. Having the ability to turn ideas into reality, communicate effectively, and work closely with others in teams around the world is essential. You\'ll use the latest tools and technologies available to deliver state-of-the-art software components. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Degree in Computer Science, Software Engineering or equivalent experience Strong command of Object Oriented Design Software development experience using C#, Java, or C++ Enthusiasm for technology and a desire to build great software Enthusiasm for technology and a desire to build great software An understanding of database theory Exceptional problem solving skills Experience with the software development life cycle Excellent verbal communication skills "
                                },
                                new Qualification {QualificationDetails = "Preferred Tech and Prof Experience "},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Excellent listener and communicator Passionate about testing and automation Self-motivated, independent worker and strong team member Proven ability to work creatively and analytically in a problem-solving environment"
                                },
                            }
                        },
                        new Job
                        {
                            Title = "Software Developer - Early Professional",
                            Salary = 45000m,
                            NoOfVacancies = 3,
                            JobLocation = new Location {City = "Markham", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(15),
                            Start_Date = DateTime.Today.AddDays(35),
                            JobDescription =
                                "This posting is for services position(s) with the IBM Cloud Software Adoption services team. In this role, you will be engaged in application development as well as complex problem determination with a number of IBM, open-source and other emerging technologies including Mobile, Cloud, Cognitive, JavaScript, and NoSQL Databases. The ideal candidate will have some exposure to IBM technologies/products and have strong development & customer facing skills. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails = "Bachelor\'s Degree (Computer Science or related)"
                                },
                                new Qualification {QualificationDetails = "Applied Knowledge of Software Development "},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Web Application development that includes experience with JavaScript, HTML, CSS, NoSQL Databases"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience with front end web frameworks (e.g. Angular, React, etc...)"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience with one or more server-side languages (e.g. NodeJS, PHP, Java etc... )"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "SCM (Source Control Management) experience with Git, SVN, or Rational Team Concert"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Applied Agile development practices: Scrum, Devops, continuous integration, continuous testing, iterative development etc."
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Strong communication skills, and the ability to work directly with clients/customers"
                                },
                            }
                        },
                    },

                },
                new Employer
                {
                    Name = "Robert Half Technology",
                    UserName = "RobertHalfTechnology",
                    Email = "employer@rht.com",
                    Rating = 0m,
                    Reviews = new List<EmployerReview>
                    {
                        new EmployerReview
                        {
                            Review = 4.0m,
                            Details =
                                "It\'s a great place to work. There are often times when we need to stretch working hours but it\'s not too hectic. The only issue is with advancing to the next level."
                        },
                        new EmployerReview
                        {
                            Review = 5.0m,
                            Details =
                                "IBM as a whole cannot be judged based on a single team. The team I worked on was fantastic. They gave me tasks that were challenging and allowed me to experiment and learn while taking the time to look and build strong solutions. There was no unfair pressure from management and the environment was inclusive and comfortable.This was an internship so my experience is limited."
                        }
                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Software Developer",
                            Salary = 75000m,
                            NoOfVacancies = 1,
                            JobLocation = new Location {City = "Ottawa", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(15),
                            Start_Date = DateTime.Today.AddDays(40),
                            JobDescription =
                                "Our client in the mobile app business is looking to add a Java Architect immediately to their growing team. This is a full-time opportunity for someone who will work with both front-end and back-end web developers to build all client-side logic as well as integrate with and develop with the Server-Side components and API\'s. The Java Architect will play an active role on both sides and define how the application looks and functions. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails = "4 years of JAVA , spring or Hibernate development "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience working with Angular.js, HTML, JavaScript, and CSS  "
                                },
                                new Qualification {QualificationDetails = "Good understanding of AJAX "},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience with Databases such as MySQL, Oracle, Microsoft SQL  "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "API design and development Java, Hibernate, Spring Framework, AngularJS  "
                                },
                            }
                        },
                    }
                },
                new Employer
                {
                    Name = "Symantec",
                    UserName = "Symantec",
                    Email = "employer@symantec.com",
                    Rating = 0m,
                    Reviews = new List<EmployerReview>
                    {
                        new EmployerReview
                        {
                            Review = 4.0m,
                            Details =
                                "The hardest part of working for Symantec is that it requires long hours depending on the department you are in. Traveling 25-60% of the time might be hard to you especially when you have young children. Overall, the environment is great and they build team spirit!!!"
                        },
                        new EmployerReview
                        {
                            Review = 4.0m,
                            Details =
                                "It is a great place.\r\n\r\nSalary is competitive including benefits.\r\n\r\nLife / work balance is great\r\n\r\nNew CEO seems to know how to run a technical company like Symantec"
                        },
                        new EmployerReview
                        {
                            Review = 3.0m,
                            Details =
                                "OK place to work, it also depends on the department you are in. Its not the whole company. For the past 4 to 5 years, the company has gone through several rounds of restructuring and layoffs."
                        },
                        new EmployerReview
                        {
                            Review = 5.0m,
                            Details =
                                "I know what I need to achieve and I am allowed to determine how best to achieve it. This draws on my skills as a manager which makes me feel valued as an employee."
                        },

                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Software Developer 4",
                            Salary = 50000m,
                            NoOfVacancies = 1,
                            JobLocation = new Location {City = "Waterloo", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(15),
                            Start_Date = DateTime.Today.AddDays(40),
                            JobDescription =
                                "The Symantec Engineering team is seeking an experienced Senior Software Developer to contribute and enhance our configuration and management services used by our suite of advanced cyber security products.\r\n\r\nWe are building out a new suite of services to manage our cloud and on premise virtual appliances using the latest in orchestration and management technologies. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails =
                                        "B.S. degree or equivalent in computer science with 5-7 years related industry experience "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Write high quality, efficient, extensible, and maintainable Java code"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Background developing applications using Java, Python or other modern languages"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience developing multithreaded applications under Linux OS (preferably CentOS) "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Good design skills to build complex applications from scratch "
                                },
                                new Qualification
                                {
                                    QualificationDetails = "Solid debugging, diagnostic and problem-solving skills"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience with containerization technologies (Docker, Kubernetes)"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Prior expertise with virtualization technologies (KVM, XEN) "
                                },
                            }
                        },
                    }
                },
                new Employer
                {
                    Name = "General Motors",
                    UserName = "GeneralMotors",
                    Email = "employer@gm.com",
                    Rating = 4.5m,
                    Reviews = new List<EmployerReview>
                    {

                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Software Developer - Audio Framework",
                            Salary = 125000m,
                            NoOfVacancies = 4,
                            JobLocation = new Location {City = "Markham", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(65),
                            Start_Date = DateTime.Today.AddDays(70),
                            JobDescription =
                                "As a Software Developer for Audio Framework, you will contribute to the development of GM’s Infotainment system. Your contribution will enable customers to connect their personal consumer devices to the vehicle infotainment system. You will be part of a new software initiative at GM Canada which is also operates as part of the larger GM global Engineering team.\r\n\r\nThis role will help GM Infotainment enable customers to use all kinds of audio scenario such as music/radio playback, BT/Onstar/Carplay call, TTS/VR and chime. Audio Framework Developers need to handle the focus control, audio routing, volume adjustment and post-processing etc. You will leverage your prior software development experience from industries such as ALSA, PulseAudio, Android Audio Aystem, EAVB etc. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Engineering,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails = "1+ years of audio/multimedia related experience "
                                },
                                new Qualification {QualificationDetails = "Knowledge of Android audio framework"},
                                new Qualification {QualificationDetails = "Knowledge of Android multimedia system"},
                                new Qualification {QualificationDetails = "Knowledge of Android device HALDomain"},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Knowledge of speech, Carplay, GAL, audio DSP, eavb, audio codec, audio chipset etc"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Software platform development experience, such as Linux and Android platform"
                                },
                                new Qualification
                                {
                                    QualificationDetails = "Commercial software development experience in C, C++, Java "
                                },
                                new Qualification
                                {
                                    QualificationDetails = "Strong OO design concepts and implementation experiences "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience with SCM tools, GIT, JIRA, Eclipse IDE, ClearCase etc. "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Experience working with Scrum/Agile software development process and tools "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Ability to perform diagnostic and investigation based on limited information "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Creative, discipline, strong sense of responsibility, delivery and schedule commitment "
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Bachelor's degree in Computer Science, Software Engineering, Electrical Engineering or equivalent field "
                                },
                            }
                        },
                    }
                },
                new Employer
                {
                    Name = "Nokia",
                    UserName = "Nokia",
                    Email = "employer@nokia.com",
                    Rating = 4.2m,
                    Reviews = new List<EmployerReview>
                    {
                        new EmployerReview
                        {
                            Review = 5.0m,
                            Details =
                                "Very flexible\r\nGood working environment\r\nWorking with different culture\r\nFree lunch frequently.\r\nGym, tim hortons.\r\nOverall, Liked working at alcatel"
                        },
                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Co-op: Web Software Developer",
                            Salary = 25000m,
                            NoOfVacancies = 4,
                            JobLocation = new Location {City = "Ottawa", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(65),
                            Start_Date = DateTime.Today.AddDays(70),
                            JobDescription =
                                "With operations in 130 countries, Nokia is the first truly global communications solutions provider, offering the most complete end-to-end portfolio of solutions and services in the industry. Our passionate and experienced team converts challenges into opportunities in the areas of third-generation mobile networking, metro optical and packet, circuit-to-packet, broadband access, advanced network and professional services, and next-generation operations support systems.\r\n\r\n    The developer will be responsible for maintaining and creating web applications, predominantly using java open source technologies.\r\n    Familiarity with at least one web application development framework (Spring Web Flow, Spring MVC, Struts, JSF, Wicket, etc.) is beneficial.\r\n    Familiarity with web presentation technologies (HTML, CSS, JavaScript, AJAX) is required.\r\n    Familiarity with the Spring framework is beneficial.\r\n    Practical experience with databases/SQL/JPA or Hibernate is beneficial.\r\n    Familiarity with Maven is beneficial.\r\n    Familiarity with JasperReports or BIRT is beneficial.\r\n    Familiarity with Subversion is beneficial.\r\n    Installation and administration of server software is beneficial.\r\n    Experience with test-driven development (especially using JUnit) is beneficial.\r\n\r\nMinimum 2nd year + co-op student registered in a recognized Co-Op or Intern Program, at a Canadian College or University; Engineering or Computer Science.",
                            MinEducationId = 6,
                            JobTypeId = 4,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Implementation of open source APIs and libraries, including Spring Framework and Hibernate"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Integration with enterprise systems (Oracle DB, MySQL, LDAP)"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Implementation of commercial and open source server technologies like Apache httpd, Apache Tomcat"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Implementation of web-based user interfaces using an MVC approach"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Familiarity with JavaScript, AJAX, especially DOJO and JQuery frameworks"
                                },
                                new Qualification {QualificationDetails = "Experience using the Eclipse IDE"},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Familiarity with HTML, CSS, XML Familiarity with test-driven and agile development approaches "
                                },
                            }
                        },
                    }
                },
                new Employer
                {
                    Name = "The Home Depot",
                    UserName = "TheDepot",
                    Email = "employer@hd.com",
                    Rating = 4.1m,
                    Reviews = new List<EmployerReview>
                    {

                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Web Developer",
                            Salary = 47500m,
                            NoOfVacancies = 1,
                            JobLocation = new Location {City = "Toronto", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(25),
                            Start_Date = DateTime.Today.AddDays(35),
                            JobDescription =
                                "Homedepot.ca is looking for website application developers to build highly scalable Java web applications that enhance our end customer experience. We are seeking a developer who has a proven track record of implementing in a business critical environment. Developers are expected to work closely with Architects, Technical Leads, QA and User Experience team in a highly collaborative environment. The ideal candidate will have recent experience with Hybris, Adobe AEM, MongoDB and native mobile development.\r\nWeb experience in Retail or other high volume customer facing web applications a strong plus. ",
                            MinEducationId = 3,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails = "Integration of frameworks like Spring, Hibernate"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Integration of proprietary solutions like Adobe AEM, Scene7, Cybersource DM, BazaarVoice, Solr"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Working with a talented, passionate team to build the best possible solutions"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Produce HTML/CSS/JavaScript code from design documentation for integrating into desktop and mobile websites and web applications"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Understand cross-browser and cross-platform concepts and concerns"
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Work closely with internal and external design, business, and technical counterparts"
                                },
                                new Qualification
                                {
                                    QualificationDetails = "Provide technical leadership at a project level"
                                },
                            }
                        },
                    }
                },
                new Employer
                {
                    Name = "Queen's University",
                    UserName = "QueenU",
                    Email = "employer@QueensU.edu",
                    Rating = 4.9m,
                    Reviews = new List<EmployerReview>
                    {
                        new EmployerReview
                        {
                            Review = 5.0m,
                            Details =
                                "Wonderful atmosphere and location/site. Great to interact with the university students. Jobs can be stressful but management is fair. Overall, this was a good experience"
                        },
                    },
                    Jobs = new List<Job>
                    {
                        new Job()
                        {
                            Title = "Senior Web Developer",
                            Salary = 58_454m,
                            NoOfVacancies = 1,
                            JobLocation = new Location {City = "Kingston", ProvinceId = 9, PostalCode = "M5A 4T3"},
                            Date_Posted = DateTime.Today,
                            Closing_Date = DateTime.Today.AddDays(50),
                            Start_Date = DateTime.Today.AddDays(85),
                            JobDescription =
                                "The Entrada Consortium at Queen’s University is seeking a Senior Web Developer who enjoys using modern service-oriented architecture techniques to develop innovative software. We require someone who has experience creating RESTful APIs and Vue.js front-ends, and finds it appealing, if not exciting, to work with a collaborative, international team to ensure Entrada is effective and user friendly.\r\n\r\nEntrada (https://entrada.org) is a community-source integrated teaching and learning platform developed by Queen’s University and 15+ other Medical Schools across North America to support the education of tomorrow’s health care professionals. With the speed at which this software is being adopted by leading educational institutions, and the emphasis on collaboration, the environment feels very much like a start-up organisation, but with the resources and benefits that accompany a large international institution like Queen’s University.\r\n\r\nThis position requires the incumbent to travel on a regular basis to consortium member institutions and will occasionally require the incumbent to work variable hours.\r\n\r\nIf you are a strong full-stack PHP developer who is excited about cutting edge technology, we encourage you to apply.",
                            MinEducationId = 4,
                            JobTypeId = 1,
                            CategoryId = (int)JobCategoryList.Information_Technology,
                            Qualifications = new List<Qualification>
                            {
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Three-year post-secondary program with a concentration in computer science or related computer technology and several years of professional PHP software development experience."
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Demonstrated proficiency in the development, implementation, and maintenance of websites and advanced web-based applications."
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Expert knowledge of PHP (including OOP concepts and design patterns)."
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Strong web-based user interface design and development skills using modern techniques."
                                },
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Knowledge of the Entrada Platform and understanding of the university environment, specifically Medical Education or a related Health Sciences related discipline and course development considered an asset. "
                                },
                                new Qualification {QualificationDetails = "A valid passport is required."},
                                new Qualification
                                {
                                    QualificationDetails =
                                        "Proficient with Linux server operating systems and maintenance."
                                },
                            }
                        },
                    }
                },
            };

            var password = "password";

            foreach (var employer in employers)
            {
                var result = userManager.CreateAsync(employer, password).Result;
                if (result.Succeeded)
                {
                    userManager.AddToRoleAsync(employer, "Employer").Wait();
                }
            }
        }
        #endregion

        #region CANDIDATES
        private static void SeedCandidates(ApplicationDbContext context, UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> role)
        {
            if (context.Candidates.Any()) return;

            var candidates = new List<Candidate>
            {
                new Candidate
                {
                    Name = "Jason Choquette",
                    UserName = "JasonChoquette",
                    Email = "Jay@email.com",
                    Location = new Location()
                    {
                        City = "Windsor",
                        ProvinceId = 9,
                        PostalCode = "N8S 4A9"
                    },
                    EducationId = 3,
                },
                 new Candidate
                {
                    Name = "Joe Smith",
                    UserName = "JoeSmith",
                    Email = "Joe@email.com",
                    Location = new Location()
                    {
                        City = "Toronto",
                        ProvinceId = 9,
                        PostalCode = "N8S 4A9"
                    },
                    EducationId = 3,
                },
                  new Candidate
                {
                    Name = "Trevor Johnson",
                    UserName = "TrevorJohnson",
                    Email = "Trevor@email.com",
                    Location = new Location()
                    {
                        City = "Quebec",
                        ProvinceId = 11,
                        PostalCode = "N8S 4A9"
                    },
                    EducationId = 3,
                },
                   new Candidate
                {
                    Name = "Melissa Baxter",
                    UserName = "Melissa Baxter",
                    Email = "Mel@email.com",
                    Location = new Location()
                    {
                        City = "Lethbridge",
                        ProvinceId = 1,
                        PostalCode = "N8S 4A9"
                    },
                    EducationId = 3,
                },
                    new Candidate
                {
                    Name = "Jen Wallace",
                    UserName = "JenWallace",
                    Email = "Jen@email.com",
                    Location = new Location()
                    {
                        City = "St.John's",
                        ProvinceId = 5,
                        PostalCode = "N8S 4A9"
                    },
                    EducationId = 3,
                },
            };

            
            var password = "password";

            foreach (var candidate in candidates)
            {
                var result = userManager.CreateAsync(candidate, password).Result;
                if (result.Succeeded)
                {
                    userManager.AddToRoleAsync(candidate, "Candidate").Wait();
                }
            }
        }

        #endregion
    }
}
