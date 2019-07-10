using System;
using System.ComponentModel.DataAnnotations;

namespace CareerWebsite.Models
{
    public class AppliedJob
    {
        public int Id { get; set; }
        public string Title { get; set; }

        [DisplayFormat(DataFormatString = "{0:MM/dd/yyyy}")]
        public DateTime DateApplied { get; set; }
        public int CandidateId { get; set; }
        public Candidate Candidate { get; set; }
    }

    public class FavouriteJob
    {
        public int Id { get; set; }
        public string Title { get; set; }      
        
        [DisplayFormat(DataFormatString = "{0:MM/dd/yyyy}")]
        public DateTime DateApplied { get; set; }
        public int CandidateId { get; set; }
        public Candidate Candidate { get; set; }
    }
}
