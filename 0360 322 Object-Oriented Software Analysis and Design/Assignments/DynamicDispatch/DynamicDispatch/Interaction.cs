using System;
using System.Collections.Generic;
using System.Linq;


namespace A3Test
{
    public class Interaction
    {
        private static List<SpaceObject> _entities;

        public Interaction(List<SpaceObject> enities) => _entities = enities;

        /*---------------------------COLLIDE---------------------------------*/

        /*----------------------------ASTEROID-------------------------------*/
        public static void Collide(Asteroid a, Asteroid b)
        {
            Console.WriteLine("Collision between the asteroid made of " + 
                              a.Matter + " and the one made of " +
                              b.Matter + ".");
        }
        public static void Collide(Asteroid a, Spaceship b)
        {
            Console.WriteLine("Collision between spaceship " + 
                              b.Name + " and asteroid " + 
                              a.Matter + ".");
        }
        public static void Collide(Asteroid a, Moon b)
        {
            Console.WriteLine("Collision between the asteroid made of " + 
                              a.Matter + " and the moon " + 
                              b.Name + ".");
        }

        /*------------------------------MOON---------------------------------*/
        public static void Collide(Moon a, Spaceship b) => Collide(b, a);
        public static void Collide(Moon a, Asteroid b)  => Collide(b, a);
        public static void Collide(Moon a, Moon b)
        {
            Console.WriteLine("Moon" + a.Name + " has collided with moon " + 
                              b.Name + ".");
        }


        /*---------------------------SPACESHIP-------------------------------*/
        public static void Collide(Spaceship a, Asteroid b) => Collide(b, a);
        public static void Collide(Spaceship a, Spaceship b)
        {

            Console.WriteLine("Catastrophic collision between spaceship " + a.Name + " and spaceship " + b.Name + ".");
            Stack<string> corpses = new Stack<string>();

            foreach (var stringaPassengers in a.Passengers)
            {
                corpses.Push(stringaPassengers);
            }

            foreach (var stringaPassengers in b.Passengers)
            {
                corpses.Push(stringaPassengers);
            }

            if (corpses.Any())
            {
                Console.WriteLine("Casualties: ");
                while (corpses.Any())
                    Console.WriteLine(corpses.Pop());
            }

            //since spaceships crashed, they are no longer entities
            _entities.Remove(a);
            _entities.Remove(b);
        }
        public static void Collide(Spaceship a, Moon b)
        {
            Console.WriteLine("Catastrophic collision between spaceship " + a.Name + " and moon " + b.Name + ".");

            Stack<String> corpses = a.Passengers;

            if (b.People.Any())
            {
                corpses.Push(b.People.Pop());
            }

            if (corpses.Any())
            {
                Console.WriteLine("Casualties: ");
                while (corpses.Any())
                    Console.WriteLine(corpses.Pop());
            }

            _entities.Remove(a);
            Console.WriteLine("");
        }

        // Collide() Dynamic Dispatcher
        public static void Collide(SpaceEntity a, SpaceEntity b)
        {
            Collide(a as dynamic, b as dynamic);
        }


        /*------------------------------LAND----------------------------------*/

        /*----------------------------ASTEROID-------------------------------*/
        public static void Land(Asteroid a, Asteroid b)
        {
            Console.WriteLine("Asteroid of matter" + a.Matter + " has \'landed\' " +
                              "on asteroid " + b.Matter + ".");
        }
        public static void Land(Asteroid a, Spaceship b) => Land(b, a);
        public static void Land(Asteroid a, Moon b)
        {
            Console.WriteLine("Asteroid of matter" + a.Matter + 
                              " has \'landed\' on moon " + b.Name + ".");
        }


        /*------------------------------MOON---------------------------------*/
        public static void Land(Moon a, Moon b)
        {
            Console.WriteLine("Moon" + a.Name + " has collided with moon " + 
                              b.Name + ".");
        } 
        public static void Land(Moon a, Spaceship b)     => Land(b, a);
        public static void Land(Moon a, Asteroid b)      => Land(b, a);


        /*---------------------------SPACESHIP-------------------------------*/
        //land a spaceship on an asteroid
        public static void Land(Spaceship a, Asteroid b)
        {
            Console.WriteLine("Spaceship " + a.Name + " landed on asteroid made up of " + b.Matter + ".");

            if (a.Passengers.Count > 0)
            {
                Console.Write("The passengers ");
                foreach (var p in a.Passengers)
                    Console.Write(p + ", ");

                Console.WriteLine("pick up some " + b.Matter + ".");
            }
        }
        public static void Land(Spaceship a, Moon b)
        {
            Console.WriteLine("Spaceship " + a.Name + " landed on the moon " + b.Name + ".");

            if (a.Passengers.Count > 0)
            {
                string defector = a.Passengers.Pop();
                Console.Write(defector + " has left the spaceship " + a.Name + ", and is setting up a farm " +
                              "on the moon " + b.Name + ".");
                b.People.Push(defector);
            }
            Console.WriteLine("");
        }
        public static void Land(Spaceship a, Spaceship b)
        {
            Console.WriteLine("Spaceship " + a.Name + " has docked " +
                              "with spaceship" + b.Name + ".");
        } 
       

        // Land() Dynamic Dispatcher
        public static void Land(SpaceEntity a, SpaceEntity b)
        {
            Land(a as dynamic, b as dynamic);
        }
    }
}
