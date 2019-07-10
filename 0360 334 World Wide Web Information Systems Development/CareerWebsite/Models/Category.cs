using System;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Reflection;

namespace CareerWebsite.Models
{
    public class Category
    {        
        public int Id { get; set; }

        [Required]
        [MaxLength(50)]
        public string Name { get; set; }        
    }

    public enum JobCategoryList
    {
        [Display(Name ="Accounting")]           Accounting = 1,
        [Display(Name ="Finance")]              Finance,
        [Display(Name ="Advertising")]          Advertising,
        [Display(Name ="Pubic Relations")]      Pubic_Relations,
        [Display(Name ="Entertainment")]        Entertainment,
        [Display(Name ="Banking")]              Banking,
        [Display(Name ="Publishing")]           Publishing,
        [Display(Name ="Mortgage")]             Mortgage,
        [Display(Name ="Clerical")]             Clerical,
        [Display(Name ="Logistics")]            Logistics,
        [Display(Name ="Research")]             Research,
        [Display(Name ="Transport")]            Transport,
        [Display(Name ="Telecommunications")]   Telecommunications,
        [Display(Name ="Social Services")]      Social_Services,
        [Display(Name ="Sales")]                Sales,
        [Display(Name ="Food Service")]         Food_Service,
        [Display(Name ="Real Estate")]          Real_Estate,
        [Display(Name ="Pharmaceutical")]       Pharmaceutical,
        [Display(Name ="Retail")]               Retail,
        [Display(Name ="Volunteer")]            Volunteer,
        [Display(Name ="Non-Profit")]           Non_Profit,
        [Display(Name ="Marketing")]            Marketing,
        [Display(Name ="Operations")]           Operations,
        [Display(Name ="Manufacturing")]        Manufacturing,
        [Display(Name ="Management Consulting")]Management_Consulting,
        [Display(Name ="Legal")]                Legal,
        [Display(Name ="Security")]             Security,
        [Display(Name ="Law Enforcement")]      Law_Enforcement,
        [Display(Name ="Media")]                Media,
        [Display(Name ="Information Technology")]Information_Technology,
        [Display(Name ="Insurance")]            Insurance,
        [Display(Name ="Human Resources")]      Human_Resources,
        [Display(Name ="Travel")]               Travel,
        [Display(Name ="Hospitatility")]        Hospitatility,
        [Display(Name ="Healthcare")]           Healthcare,
        [Display(Name ="Military")]             Military,
        [Display(Name ="Government")]           Government,
        [Display(Name ="Engineering")]          Engineering,
        [Display(Name ="Education")]            Education,
    }                                
    

    public static class EnumExtensions
    {
        public static string GetDisplayName(this Enum value) => 
            value
            .GetType()
            .GetMember(value.ToString())
            .First().GetCustomAttribute<DisplayAttribute>()
            .GetName();
    }
}
