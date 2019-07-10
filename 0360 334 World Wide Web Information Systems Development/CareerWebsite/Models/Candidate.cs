using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Candidate : ApplicationUser
    {
        public Candidate()
        {
            FavouriteJobs = new HashSet<FavouriteJob>();
            AppliedJobs = new HashSet<AppliedJob>();
        }
        [Required]
        [MaxLength(60)]
        public string Name { get; set; }
        [Required]
        public Location Location { get; set; }

        public ICollection<FavouriteJob> FavouriteJobs { get; set; }
        public ICollection<AppliedJob> AppliedJobs { get; set; }

        public int EducationId { get; set; }
        public Education MaxEducation { get; set; }
    }
}
