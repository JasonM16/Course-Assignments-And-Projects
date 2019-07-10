

namespace A3Test
{
    public class Asteroid : SpaceObject
    {
        public string Matter { get; set; }
        public Asteroid(string matter) => Matter = matter;
        public override void Accept(IVisitor visitor) => visitor.Visit(this);
    }
}
