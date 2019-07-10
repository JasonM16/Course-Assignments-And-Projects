import java.util.ArrayList;

public abstract class Entity {

    //
    public abstract void accept(EntityVisitor v);       // Used to accept visits

    //
    public static ArrayList<Entity> entities = new java.util.ArrayList<>();

    //
    public abstract void doCollision(Asteroid e);       // collide with Asteroid

    //
    public abstract void doCollision(Moon m);           // collide with moon

    //
    public abstract void doCollision(Spaceship e);      // collide with Spaceship

    //
    public abstract void doLand(Asteroid e);            // collide with planet

    //
    public abstract void doLand(Spaceship s);           // collide with planet

    //
    public abstract void doLand(Moon m);                // collide with planet
}

