using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;
using Microsoft.AspNetCore.Authorization;
using ReflectionIT.Mvc.Paging;
using Microsoft.AspNetCore.Mvc.Rendering;
using CareerWebsite.Data;
using Microsoft.EntityFrameworkCore;
using System;

namespace CareerWebsite.Controllers
{
    [Authorize(Roles = "Employer, Admins")]
    public class JobsController : Controller
    {
        private readonly IJobRepository _context;
        private readonly ApplicationDbContext _dbContext;
        public JobsController(IJobRepository context, ApplicationDbContext dbContext)
        {
            _context = context;
            _dbContext = dbContext;
        }

        
        [AllowAnonymous]
        // GET: Jobs
        public IActionResult Index(string sortOrder, string currentFilter, string searchString, int? page)
        {
            List<Job> jobs = _context.Jobs;
            List<Job> j2 = new List<Job>();
            // different list of jobs based on user
            if(User.IsInRole(nameof(Employer)))
            {
                jobs = _context.GetJobsByEmployerName(User.Identity.Name).Result;
            }

            else
            {
                if (searchString != null) page = 1;            
                else searchString = currentFilter;
            
                ViewBag.CurrentFilter = searchString;
            

                if (!string.IsNullOrEmpty(searchString))
                {                
                    j2.AddRange(_context.GetJobsByTitle(searchString).Result);
                    j2.AddRange(_context.GetJobsByCity(searchString).Result);
                    j2.AddRange(_context.GetJobsByEmployerName(searchString).Result);
                }            

                if(j2.Any())
                {
                    jobs = new List<Job>();
                    jobs.AddRange(j2);
                }          
            }            

            int pageSize = 10;
            int pageNumber = (page ?? 1);
            ViewBag.PageNumber = pageNumber;           
            var model = PagingList.Create(jobs, pageSize, pageNumber);

            return View(model);
        }

        [AllowAnonymous]
        // GET: Jobs/Details/5
        public async Task<IActionResult> Details(int id)
        {
            var job = await _context.GetJobById(id);            
            if (job == null)
            {
                return NotFound();
            }

            return View(job);
        }

        //GET: Jobs/Create
        public IActionResult Create()
        {
            ViewData["JobTypeId"] = new SelectList(_dbContext.JobTypes, "Id", "Name");
            ViewData["MinEducationId"] = new SelectList(_dbContext.Education, "Id", "Name");
            ViewData["ProvinceId"] = new SelectList(_dbContext.Provinces, "Id", "Name");
            ViewData["CategoryId"] = new SelectList(_dbContext.Categories, "Id", "Name");
            return View(new Job());
        }

        // POST: Jobs/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create(/*[Bind("Title,Salary,NoOfVacancies,JobDescription,ocation_City,JobLocation_ProvinveId,JobLocation_PostalCode,Closing_Date,Start_Date,MinEducationId,JobTypeId")]*/ Job job) //, Location.ProvinceId, Location.City, Location.PostalCode
        {            
            var employer = _context.GetEmployer(User.Identity.Name);
            job.Employer = employer;            
            job.Date_Posted = DateTime.Today;


            if (ModelState.IsValid)
            {
                _dbContext.Add(job);
                await _dbContext.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["JobTypeId"] = new SelectList(_dbContext.JobTypes, "Id", "Name", job.JobTypeId);
            ViewData["MinEducationId"] = new SelectList(_dbContext.Education, "Id", "Name", job.MinEducationId);
            ViewData["ProvinceId"] = new SelectList(_dbContext.Provinces, "Id", "Name", job.JobLocation.ProvinceId);
            ViewData["CategoryId"] = new SelectList(_dbContext.Categories, "Id", "Name", job.CategoryId);
            return View(job);
        }

        // GET: Jobs/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var job = await _dbContext.Jobs.SingleOrDefaultAsync(m => m.Id == id);
            if (job == null)
            {
                return NotFound();
            }
            ViewData["JobTypeId"] = new SelectList(_dbContext.JobTypes, "Id", "Name", job.JobTypeId);
            ViewData["MinEducationId"] = new SelectList(_dbContext.Education, "Id", "Name", job.MinEducationId);
            ViewData["ProvinceId"] = new SelectList(_dbContext.Provinces, "Id", "Name", job.JobLocation.ProvinceId);
            ViewData["CategoryId"] = new SelectList(_dbContext.Categories, "Id", "Name", job.CategoryId);
            return View(job);
        }

        // POST: Jobs/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, /*[Bind("Id,Title,Salary,NoOfVacancies,JobDescription,Closing_Date,Start_Date,MinEducationId,JobTypeId")]*/ Job job)
        {
            if (id != job.Id)
            {
                return NotFound();
            }

            var employer = _context.GetEmployer(User.Identity.Name);
            job.Employer = employer;            
            job.Date_Posted = DateTime.Today;

            if (ModelState.IsValid)
            {
                try
                {
                    _dbContext.Update(job);
                    await _dbContext.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!JobExists(job.Id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            ViewData["JobTypeId"] = new SelectList(_dbContext.JobTypes, "Id", "Name", job.JobTypeId);
            ViewData["MinEducationId"] = new SelectList(_dbContext.Education, "Id", "Name", job.MinEducationId);
            ViewData["ProvinceId"] = new SelectList(_dbContext.Provinces, "Id", "Name", job.JobLocation.ProvinceId);
            ViewData["CategoryId"] = new SelectList(_dbContext.Categories, "Id", "Name", job.CategoryId);
            return View(job);
        }

        // GET: Jobs/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var job = await _dbContext.Jobs
                .Include(j => j.JobType)
                .Include(j => j.MinEducation)
                .SingleOrDefaultAsync(m => m.Id == id);
            if (job == null)
            {
                return NotFound();
            }

            return View(job);
        }

        // POST: Jobs/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var job = await _dbContext.Jobs.SingleOrDefaultAsync(m => m.Id == id);
            _dbContext.Jobs.Remove(job);
            await _dbContext.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool JobExists(int id)
        {
            return _context.Jobs.Any(e => e.Id == id);
        }
    }
}
