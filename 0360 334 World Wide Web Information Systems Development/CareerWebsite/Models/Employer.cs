using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Employer : ApplicationUser
    {
        public Employer()
        {
            Jobs = new HashSet<Job>();
            Reviews = new HashSet<EmployerReview>();
        }

        [Required]
        [MaxLength(40)]
        [Display(Name = "Company")]
        public string Name { get; set; }
        public ICollection<Job> Jobs { get; set; }
        public ICollection<EmployerReview> Reviews { get; set; }
        public decimal Rating { get; set; }
    }
}
