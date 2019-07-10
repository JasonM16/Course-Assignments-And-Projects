/*
    Assignment 3
    CS 322
    Jason Choquette
    104337378
    03/20/18

    Refactoring Perl6 method dispatching code to Java.
    Since Java does not have built-in multi-method dispatching, we
    need to break many good code practices. I.e., when adding a new
    type of interaction, we must go into each Entity type and add
    new functionality. This violates open-closed principle.
    Also, each entity must know about the other entities. This causes
    multiple dependencies where there should not be any.

    Also, each class type has logic instead of having just properties and
    methods. This violates the single-responsibility principle.
 */


import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;


public class Main {

    // delegate/callback
    public interface IFunction {
        void function(Entity e1, Entity e2);
    }

    //
    private static void collide(Entity e1, Entity e2) {
        EntityVisitor ev = new CollidesWithVisitor(e2);
        e1.accept(ev);
    }

    //
    private static void land(Entity e1, Entity e2) {
        EntityVisitor ev = new LandsOnVisitor(e2);
        e1.accept(ev);
    }

    //
    public static void main(String[] args) {

        final int iterations = 6;

        Entity.entities.add(new Asteroid("rock"));
        Entity.entities.add(new Asteroid("ice and dirt"));
        Entity.entities.add(new Spaceship("Relativity", new Stack<String>(){{ add("Mr. X"); add("Ms. Y");}}));
        Entity.entities.add(new Spaceship("Endeavour",  new Stack<String>(){{ add("Mr. Q"); add("Ms. R");}}));
        Entity.entities.add(new Moon("Phobos", new Stack<String>() {{ add("Mr. M"); add("Ms. N"); }}));
        Entity.entities.add(new Moon("Deimos", new Stack<String>() {{ add("Mr. J"); add("Ms. K"); }}));
        Entity.entities.add(new Asteroid("diamond"));
        Entity.entities.add(new Asteroid("uranium"));
        Entity.entities.add(new Spaceship("Andromeda", new Stack<String>(){{add("Qbert"); add("Marvin");}}));
        Entity.entities.add(new Spaceship("Steve", new Stack<String>(){{add("Pacman"); add("Inky");}}));
        Entity.entities.add(new Moon("Phobos", new Stack<String>(){{add("Croft"); add("Jones");}}));
        Entity.entities.add(new Moon("Deimos", new Stack<String>(){{add("Neo"); add("Trinity");}}));

        // generate random collisions and landings
        executeVisits(Entity.entities, Main::collide, iterations);
        executeVisits(Entity.entities, Main::land, iterations);
    }


    private static void executeVisits(ArrayList<Entity> entities, IFunction f, int iterations) {

        int count = iterations;
        Random randomizer = new Random();

        while(count-- != 0)
        {
            Entity e1 = entities.get(randomizer.nextInt(entities.size()));
            Entity e2 = entities.get(randomizer.nextInt(entities.size()));
            f.function(e1, e2);
        }
    }
}
