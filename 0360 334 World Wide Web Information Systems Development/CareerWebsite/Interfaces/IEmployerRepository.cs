using System.Collections.Generic;
using CareerWebsite.Models;

namespace CareerWebsite.Interfaces
{
    public interface IEmployerRepository
    {
        List<Employer> Employers { get; }       
        Employer GetEmployer(string userName);
        List<Job> GetEmployersJobs(string userName);
    }
}
