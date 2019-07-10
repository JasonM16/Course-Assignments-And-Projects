using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class JobType
    {
        public int Id { get; set; }
        [Required]
        [MaxLength(35)]
        public string Name { get; set; }
    }
}
