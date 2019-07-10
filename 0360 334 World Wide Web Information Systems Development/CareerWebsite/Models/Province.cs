using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Province
    {
        public int Id { get; set; }
        [Required]
        [MaxLength(45)]
        public string Name { get; set; }
        [Required]
        [MaxLength(2)]
        public string ShortName { get; set; }
    }
}
