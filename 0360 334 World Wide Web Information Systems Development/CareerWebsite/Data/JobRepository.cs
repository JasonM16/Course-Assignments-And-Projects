using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;
using Microsoft.EntityFrameworkCore;

namespace CareerWebsite.Data
{
    public class JobRepository : IJobRepository
    {
        private readonly ApplicationDbContext _context;

        public JobRepository(ApplicationDbContext context) => _context = context;

        public Employer GetEmployer(string employerName) => 
            _context.Employers.FirstOrDefault(e => e.UserName == employerName);


        public void AddJob(Job job)
        {
            _context.Jobs.Add(job);
            _context.SaveChangesAsync();
        }

        public void UpdateJob(Job job)
        {
            _context.Jobs.Update(job);
            _context.SaveChangesAsync();
        }

        public void RemoveJob(Job job)
        {
            _context.Jobs.Remove(job);
            _context.SaveChangesAsync();
        }

        public List<Job> Jobs => 
            _context.Jobs
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .Include(l => l.JobLocation)
                .ToList();

        public Task<Job> GetJobById(int id) => 
            _context.Jobs
                .Where(m => m.Id == id)
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .FirstOrDefaultAsync();
                


        public Task<List<Job>> GetJobsByCity(string city) => 
            _context.Jobs
                .Where(c => c.JobLocation.City == city)
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();
        

       public Task<List<Job>> GetJobsByEmployerName(string employerName) =>
            _context.Jobs
                .Where(c => c.Employer.UserName == employerName)
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();

        public Task<List<Job>> GetJobsBySearchString(string searchString) =>
            _context.Jobs
                .Where(s => s.Title.Contains(searchString) || s.Employer.Name.Contains(searchString))
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();

        

        public Task<List<Job>> GetJobsByStartDate(DateTime startDate) =>
            _context.Jobs
                .Where(c => c.Closing_Date == startDate)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();
        

        public Task<List<Job>> GetJobsByClosingDate(DateTime closingDate) =>
            _context.Jobs
                .Where(c => c.Closing_Date == closingDate)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();


        public Task<List<Job>> GetJobsByTitle(string title) => 
            _context.Jobs
                .Where(c => c.Title.Contains(title))
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .Include(e => e.Employer)
                .ToListAsync();

        public List<Category> GetJobCategories() => 
             _context.Categories.ToList();       
       
    }
}
