using System.ComponentModel.DataAnnotations;


namespace CareerWebsite.Models
{
    public class File
    {
        public int FileId { get; set; }
        [StringLength(80)]
        public string FileName { get; set; }
        [StringLength(80)]
        public string ContentType { get; set; }
        public byte[] Content { get; set; }
        public FileType FileType { get; set; }
        
    }

    public enum FileType
    {
        Photo,
        Resume,
        CoverLetter
    }
}
