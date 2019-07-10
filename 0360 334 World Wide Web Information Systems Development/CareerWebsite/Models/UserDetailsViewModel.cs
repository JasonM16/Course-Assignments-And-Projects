using System.Collections.Generic;

namespace CareerWebsite.Models
{
    public class UserDetailsViewModel
    {
        public UserDetailsViewModel()
        {
            AppliedJobs = new List<AppliedJob>();
            FavouriteJobs = new List<FavouriteJob>();
        }

        public List<AppliedJob> AppliedJobs { get; set; }
        public List<FavouriteJob> FavouriteJobs { get; set; }
    }
}