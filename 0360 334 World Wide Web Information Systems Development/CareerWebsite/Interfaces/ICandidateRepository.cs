using System.Collections.Generic;
using CareerWebsite.Models;

namespace CareerWebsite.Interfaces
{
    public interface ICandidateRepository
    {
        IEnumerable<Candidate> Candidates { get; }
        IEnumerable<Job> Jobs { get; }
        Job FindJobById(int id);
        List<AppliedJob> GetCandidateAppliedJobs(string userName);
        List<FavouriteJob> GetCandidateFavouriteJobs(string userName);
        void AddFavouriteJob(string userName, int id);
        void AddAppliedJob(string userName, int id);        
        Candidate GetCandidate(string userName);
        void RemoveFavouriteJob(int id);
        void RemoveAppliedJob(int id);
        //Candidate GetCandidateByUserName(string userName);
        //Candidate GetCandidateByEmail(string email);

    }
}
