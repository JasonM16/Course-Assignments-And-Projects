using System.Collections.Generic;
using CareerWebsite.Interfaces;
using CareerWebsite.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;

namespace CareerWebsite.Controllers
{
    [Authorize(Roles = nameof(Candidate))]
    public class CandidateController : Controller
    {
        private readonly ICandidateRepository _context;
        private readonly UserManager<ApplicationUser> _userManager;
        public CandidateController(ICandidateRepository context, UserManager<ApplicationUser> userManager)
        {
            _context = context;
            _userManager = userManager;
        }
        public ActionResult Apply(int id)
        {           
            _context.AddAppliedJob(User.Identity.Name, id);            
            return RedirectToAction(nameof(Index));
        }

        public ActionResult Favourites(int id)
        {
            _context.AddFavouriteJob(User.Identity.Name, id);  
            return RedirectToAction(nameof(Index));
        }

         public ActionResult RemoveAppliedJob(int id)
        {           
            _context.RemoveAppliedJob(id);            
            return RedirectToAction(nameof(Index));
        }

        public ActionResult RemoveFavouriteJob(int id)
        {
            _context.RemoveFavouriteJob(id);  
            return RedirectToAction(nameof(Index));
        }


        // GET: Candidate
        public ActionResult Index()
        {           
            var fj = _context.GetCandidateFavouriteJobs(User.Identity.Name);
            var aj = _context.GetCandidateAppliedJobs(User.Identity.Name);
            var model = new UserDetailsViewModel
            {
                AppliedJobs = aj,
                FavouriteJobs = fj
            };
            return View(model);
        }

        // GET: Candidate/Details/5
        public ActionResult Details(int? id)
        {
            var candidate = _context.GetCandidate(User.Identity.Name);
            return View(candidate);
        }

        // GET: Candidate/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Candidate/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create(IFormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }

        // GET: Candidate/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Candidate/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit(int id, IFormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }

        // GET: Candidate/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Candidate/Delete/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id, IFormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }
    }
}