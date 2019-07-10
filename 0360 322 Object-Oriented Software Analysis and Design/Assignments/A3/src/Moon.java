import java.util.Stack;


public class Moon extends Entity {

    //
    private String name;

    //
    private Stack<String> people;

    //
    public Moon(String name, Stack<String> people) { this.name = name; this.people = people; }

    //
    public String getName()                     { return name; }

    public Stack<String> getPeople()            { return people; }

    //
    public void accept(EntityVisitor v)         { v.visit(this); }

    public void doCollision(Asteroid e)         { Interaction.collide(this, e);}

    //
    public void doLand(Asteroid e)              { Interaction.land(this, e); }

    //
    public void doCollision(Spaceship e)        { Interaction.collide(this, e);}

    //
    public void doLand(Spaceship s)             { Interaction.land(this, s);}

    //
    public void doCollision(Moon m)             { Interaction.collide(this, m);}

    //
    public void doLand(Moon m)                  { Interaction.land(this, m);}
}
