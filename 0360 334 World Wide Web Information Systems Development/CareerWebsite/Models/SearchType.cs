using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace CareerWebsite.Models
{
    public enum SearchType : int
    {
        Title,
        Employer,
        City,
        ClosingDate,
        StartDate,
    }
}
