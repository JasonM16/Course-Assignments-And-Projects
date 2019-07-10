public class Asteroid extends Entity {

    // what is the asteroid made of?
    private String matter;

    // create an Asteroid
    public Asteroid(String matter)          { this.matter = matter; }

    //
    public String getMatter()               { return matter; }

    //
    public void accept(EntityVisitor v)     { v.visit(this); }

    // asteroid-asteroid collision
    public void doCollision(Asteroid a)     { Interaction.collide(this, a); }

    // asteroid-spaceship collision
    public void doCollision(Spaceship s)    { Interaction.collide(this, s); }

    // asteroid-moon collision
    public void doCollision(Moon m)         { System.out.println(""); }

    // asteroid-asteroid landing
    public void doLand(Asteroid a)          { Interaction.collide(this, a); }

    // spaceship-asteroid landing
    public void doLand(Spaceship s)         { Interaction.collide(this, s); }

    // spaceship-asteroid landing
    public void doLand(Moon m)              { Interaction.collide(this, m); }
}
