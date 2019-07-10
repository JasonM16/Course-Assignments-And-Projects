using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using CareerWebsite.Models;

namespace CareerWebsite.Interfaces
{
    public interface IJobRepository
    {
        List<Job> Jobs { get; }
        void AddJob(Job job);
        void UpdateJob(Job job);
        void RemoveJob(Job job);
        Task<Job> GetJobById(int id);
        Task<List<Job>> GetJobsByEmployerName(string employerName);
        Task<List<Job>> GetJobsByTitle(string title);
        Task<List<Job>> GetJobsByCity(string city);
        //Task<List<Job>> GetJobsByCategory(string category);
        Task<List<Job>> GetJobsByStartDate(DateTime startDate);
        Task<List<Job>> GetJobsByClosingDate(DateTime closingDate);
        Employer GetEmployer(string employerName);
        List<Category> GetJobCategories();
    }
}
