using System;
using System.Collections.Generic;
using System.Linq;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;


namespace CareerWebsite.Data
{
    public class CandidateRepository : ICandidateRepository
    {
        private readonly ApplicationDbContext _context;        

        public CandidateRepository(ApplicationDbContext context) 
            => _context = context;                   
        

        public IEnumerable<Candidate> Candidates => 
            _context.Candidates;

        public IEnumerable<Job> Jobs => 
            _context.Jobs;
        
        public Job FindJobById(int id) => 
            _context.Jobs.Find(id);

        public Candidate GetCandidate(string userName) => 
            _context.Candidates.FirstOrDefault(u => u.UserName == userName);
          
        public List<FavouriteJob> GetCandidateFavouriteJobs(string userName) =>      
            _context.FavouriteJobs.Where(c => c.Candidate.UserName == userName).ToList();

        public List<AppliedJob> GetCandidateAppliedJobs(string userName) =>
            _context.AppliedJobs.Where(c => c.Candidate.UserName == userName).ToList();       


        public void AddFavouriteJob(string userName, int id)
        {
            var candidate = GetCandidate(userName);
            var job = FindJobById(id);

            candidate.FavouriteJobs.Add(new FavouriteJob
            {
                DateApplied = DateTime.Today,
                Title = job.Title
            });

            _context.SaveChanges();
        }

        public void AddAppliedJob(string userName, int id)
        {
            var candidate = GetCandidate(userName);
            var job = FindJobById(id);

            candidate.AppliedJobs.Add(new AppliedJob
            {
                DateApplied = DateTime.Today,
                Title = job.Title
            });

            _context.SaveChanges();
        }

        public void RemoveFavouriteJob(int id)
        {            
            var job = _context.FavouriteJobs.Find(id);
            _context.FavouriteJobs.Remove(job);
            _context.SaveChanges();
        }

       
        public void RemoveAppliedJob(int id)
        {
             var job = _context.AppliedJobs.Find(id);
            _context.AppliedJobs.Remove(job);
            _context.SaveChanges();
        }

    }
}
