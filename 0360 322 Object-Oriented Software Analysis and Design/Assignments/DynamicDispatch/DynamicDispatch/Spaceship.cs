using System.Collections.Generic;


namespace A3Test
{
    public class Spaceship : SpaceObject
    {
        public string Name { get;  }
        public Stack<string> Passengers { get;  }


        public Spaceship(string name, Stack<string> passengers)
        {
            Name = name;
            Passengers = passengers;
        }

        public override void Accept(IVisitor visitor) => visitor.Visit(this);
    }
}
