using System.Collections.Generic;
using System.Linq;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;

namespace CareerWebsite.Data
{
    public class EmployerRepository : IEmployerRepository
    {
        private ApplicationDbContext _context;

        public EmployerRepository(ApplicationDbContext context) =>
            _context = context;               

        public List<Employer> Employers => 
            _context.Employers.ToList();

        public Employer GetEmployer(string userName) =>
            _context.Employers.FirstOrDefault(u => u.UserName == userName);         

        public List<Job> GetEmployersJobs(string userName)
        {
            var emp = GetEmployer(userName);
            return _context.Jobs.Where(e => e.Employer.UserName == emp.UserName).ToList();            
        }
    }
}
