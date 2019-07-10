namespace CareerWebsite.Models
{
    public class CandidateFavouriteJobs
    {
        public int CandidateId { get; set; }
        public Candidate Candidate { get; set; }
        public int JobId { get; set; }
        public Job Job { get; set; }
    }
}
