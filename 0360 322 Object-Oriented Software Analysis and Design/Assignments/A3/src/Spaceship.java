import java.util.Stack;

public class Spaceship extends Entity {

    // name of spaceship
   private String name;

    // names of passengers
   private Stack<String> passengers;

    // create a Spaceship
    public Spaceship(String name, Stack<String> pass)           { this.name = name; this.passengers = pass; }

    //
    public String getName()                                     { return name; }

    //
    public Stack<String> getPassengers()                        { return passengers; }

    public void setPassengers(Stack<String> newPassengers)      { this.passengers = newPassengers; }

    //
    public void accept(EntityVisitor v)                         { v.visit(this); }

    // spaceship-asteroid collision
    public void doCollision(Asteroid e)                         { Interaction.collide(this, e); }

    // spaceship-spaceship collision
    public void doCollision(Spaceship e)                        { Interaction.collide(this, e); }

    // spaceship-moon collision
    public void doCollision(Moon m)                             { Interaction.collide(this, m); }

    // spaceship-asteroid landing
    public void doLand(Asteroid a)                              { Interaction.land(this, a); }

    // spaceship-spaceship landing
    public void doLand(Spaceship s)                             { Interaction.land(this, s);}

    // spaceship-moon landing
    public void doLand(Moon m)                                  { Interaction.land(this, m);}
}
