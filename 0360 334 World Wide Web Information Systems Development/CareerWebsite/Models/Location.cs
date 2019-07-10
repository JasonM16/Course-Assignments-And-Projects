using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class Location
    {
        public int Id { get; set; }
        [Required]
        [MaxLength(40)]
        public string City { get; set; }

        [Required]
        [MaxLength(10)]
        [Display(Name = "Postal Code")]
        public string PostalCode { get; set; }

        //----------- Navigation Properties -----------------

        public int ProvinceId { get; set; }
        public Province Province { get; set; }
    }
}
