using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


namespace A3Test
{
    class Program
    {
        public static void Main(string[] args)
        {
            int iter = 6;
            SpaceObject so = new SpaceObject
            {
                Entities = 
                {
                    new Asteroid("Rock"),
                    new Asteroid("Ice and Dirt"),
                    new Spaceship("Relativity", new List<string> { "Mr. X", "Ms. Y" }.ToStack()), 
                    new Spaceship("Endeavour", new List<string> { "Mr. Q", "Ms. R" }.ToStack()),
                    new Moon("Phobos", new List<string> { "Mr. M", "Ms. N" }.ToStack()),
                    new Moon("Deimos", new List<string>() { "Mr. J", "Ms. K" }.ToStack()),

                    new Asteroid("Diamond"),
                    new Asteroid("Uranium"),
                    new Spaceship("Andromeda", new List<string> { "Mr. X", "Ms. Y" }.ToStack()), 
                    new Spaceship("Steve", new List<string> { "Mr. Q", "Ms. R" }.ToStack()),
                    new Moon("Europa", new List<string> { "Mr. A", "Ms. B" }.ToStack()),
                    new Moon("Io", new List<string>() { "Mr. T", "Ms. T" }.ToStack()),
                }
            };

            Interaction i = new Interaction(so.Entities);

            ExecuteVisit(so.Entities, Land, iter);
            ExecuteVisit(so.Entities, Collide, iter);

            Console.ReadLine();
        }


        static void ExecuteVisit(List<SpaceObject> entities, Action<SpaceObject, SpaceObject> act, int iter)
        {
            int count = iter;
            Random rand = new Random();

            while (iter-- != 0)
            {

                SpaceObject e1 = entities.OrderBy(r => rand.Next()).First();
                SpaceObject e2 = entities.OrderBy(r => rand.Next()).First();
                act.Invoke(e1, e2);
            }

        }

        static void Land(SpaceObject e1, SpaceObject e2)
        {
            IVisitor ev = new CollidesWithVisitor(e2);
            e1.Accept(ev);
        }


        static void Collide(SpaceObject e1, SpaceObject e2)
        {
            IVisitor ev = new LandsOnVisitor(e2);
            e1.Accept(ev);
        }

    }
}
