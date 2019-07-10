using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Qualification
    {
        public int Id { get; set; }
        [Required]
        public string QualificationDetails { get; set; }
    }
}