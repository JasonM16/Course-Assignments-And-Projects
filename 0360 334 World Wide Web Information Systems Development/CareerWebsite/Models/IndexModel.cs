using System.Collections.Generic;
using System.Linq;
using Microsoft.AspNetCore.Identity;

namespace CareerWebsite.Models
{
    public class IndexModel
    {
        public Dictionary<string, List<ApplicationUser>> Users { get; set; }
        public IQueryable<IdentityRole> Roles { get; set; }
    }
}