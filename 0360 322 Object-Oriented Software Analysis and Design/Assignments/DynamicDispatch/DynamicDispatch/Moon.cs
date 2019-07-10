using System.Collections.Generic;


namespace A3Test
{
    public class Moon : SpaceObject
    {
        public string Name { get; set; }
        public Stack<string> People { get; set; }


        public Moon(string name, Stack<string> people)
        {
            Name = name;
            People = people;
        }


        public override void Accept(IVisitor visitor) => visitor.Visit(this);
    }
}
