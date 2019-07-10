using CareerWebsite.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CareerWebsite.Controllers
{
    [Authorize(Roles = "Employer")]
    public class EmployerController : Controller
    {
        private readonly IEmployerRepository _context;

        public EmployerController(IEmployerRepository context) => _context = context;

        // GET: Employer
        public ActionResult Index()
        {         
            var jobs = _context.GetEmployersJobs(User.Identity.Name);
            return View(jobs);
        }

        // GET: Employer/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }       
    }
}