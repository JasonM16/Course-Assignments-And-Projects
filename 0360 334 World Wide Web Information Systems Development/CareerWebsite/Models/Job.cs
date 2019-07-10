using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;


namespace CareerWebsite.Models
{
    public class Job
    {
        public Job()
        {
            Qualifications = new HashSet<Qualification>();            
            JobLocation = new Location();
        }

        public int Id { get; set; }        
        
        [Required]
        [MaxLength(45)]
        public string Title { get; set; }

        [Required]
        [DisplayFormat(DataFormatString = "{0:C}", ApplyFormatInEditMode = true)]
        public decimal Salary { get; set; }
        
        [Required]
        [Display(Name = "Vacancies")]
        [Range(1, 25, ErrorMessage = "Please enter a value between 1 and 25.")]
        public int NoOfVacancies { get; set; }
                
        [Required]
        [Display(Name = "Job Description")]
        public string JobDescription { get; set; }
                
        [Required]
        public Location JobLocation { get; set; }
        
        
        [DisplayFormat(DataFormatString = "{0:MM/dd/yyyy}")]
        [Display(Name = "Date Posted")]
        public DateTime Date_Posted { get; set; }
        
        
        [Required]
        [DataType(DataType.Date)]
        [DisplayFormat(DataFormatString = "{0:MM/dd/yyyy}", ApplyFormatInEditMode = true)]
        [Display(Name = "Closing Date")]
        public DateTime Closing_Date { get; set; }
        
        
        [Required]
        [DataType(DataType.Date)]
        [DisplayFormat(DataFormatString = "{0:MM/dd/yyyy}", ApplyFormatInEditMode = true)]
        [Display(Name = "Start Date")]
        public DateTime Start_Date { get; set; }
        
       
        public ICollection<Qualification> Qualifications { get; set; }

        //----------- Navigation Properties -----------------
        public int MinEducationId { get; set; }
        [Display(Name = "Required Education")]
        public Education MinEducation { get; set; }

        public int JobTypeId { get; set; }
        [Display(Name = "Job Type")]
        public JobType JobType { get; set; }
        
        public int EmployerId { get; set; }
        public Employer Employer { get; set; }
        
        public int CategoryId { get; set; }
        public Category Category { get; set; }
    }
}
