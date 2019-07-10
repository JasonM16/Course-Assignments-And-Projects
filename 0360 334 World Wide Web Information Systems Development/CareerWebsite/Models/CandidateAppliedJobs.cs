using System.Collections.Generic;


namespace CareerWebsite.Models
{
    public class CandidateAppliedJobs
    {
        public int CandidateId { get; set; }
        public Candidate Candidate { get; set; }
        public int JobId { get; set; }
        public ICollection<Job> Jobs { get; set; }
    }
}
