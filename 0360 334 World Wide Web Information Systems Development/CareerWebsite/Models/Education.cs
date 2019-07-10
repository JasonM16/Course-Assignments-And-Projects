using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Education
    {
        public int Id { get; set; }
        [Required]
        [MaxLength(50)]
        public string Name { get; set; }
    }
}
