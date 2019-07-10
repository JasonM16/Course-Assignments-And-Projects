import java.util.Stack;

public class Interaction {

    // collide two asteroids
    public static void collide(Asteroid a, Asteroid b) {
        System.out.println("Collision between the asteroid made of " + a.getMatter() + " and the one made of " + b.getMatter() + ".");
    }

    // collide an asteroid and a spaceship
    public static void collide(Asteroid a, Spaceship b) {
        System.out.println("Collision between spaceship " +  b.getName() + " and asteroid " + a.getMatter() + ".");
    }

    // collide a spaceship and an asteroid
    public static void collide(Spaceship a, Asteroid b) {
        collide(b, a);
    }

    // collide two spaceships
    public static void collide(Spaceship a, Spaceship b) {

        System.out.println("Catastrophic collision between spaceship " + a.getName() + " and spaceship " + b.getName() + ".");
        Stack<String> corpses = new Stack<>();

        for(String aPassengers: a.getPassengers()) {
            corpses.push(aPassengers);
        }

        for(String bPassengers: b.getPassengers()) {
            corpses.push(bPassengers);
        }

        if(!corpses.isEmpty()) {
            System.out.println("Casualties: ");
            while(!corpses.isEmpty())
                System.out.println(corpses.pop());
        }

        // since spaceships crashed, they are no longer entities
        Entity.entities.remove(a);
        Entity.entities.remove(b);
    }

    // collide a spaceship and a moon
    public static void collide(Spaceship a, Moon b) {
        System.out.println("Catastrophic collision between spaceship " + a.getName() + " and moon " + b.getName() + ".");

        Stack<String> corpses = a.getPassengers();

        if(!b.getPeople().isEmpty()) {
            corpses.push(b.getPeople().pop());
        }

        if(!corpses.isEmpty()) {
            System.out.println("Casualties: ");
            while(!corpses.isEmpty())
                System.out.println(corpses.pop());
        }

        Entity.entities.remove(a);
        System.out.println("");
    }

    // collide a spaceship and a moon
    public static void collide(Moon a, Spaceship b) {
        collide(b, a);
    }

    // catch-all collide() : do nothing
    public static void collide(Entity a, Entity b) {
        // nothing
    }

    // land a spaceship on an asteroid
    public static void land(Spaceship a, Asteroid b) {
        System.out.println("Spaceship " + a.getName() + " landed on asteroid made up of " + b.getMatter() + ".");

        if(a.getPassengers().size() > 0) {
            System.out.print("The passengers ");
            for(String p: a.getPassengers())
                System.out.print(p + ", ");

            System.out.println("pick up some " + b.getMatter() + ".");
        }
    }

    // land a spaceship on an asteroid
    public static void land(Asteroid a, Spaceship b) { land(b, a); }


    // land a spaceship on a moon
    public static void land(Spaceship a, Moon b) {
        System.out.println("Spaceship " + a.getName() + " landed on the moon " + b.getName() + ".");

        if(a.getPassengers().size() > 0) {
            String defector = a.getPassengers().pop();
            System.out.print(defector + " has left the spaceship " + a.getName() + ", and is setting up a farm " +
                    "on the moon " + b.getName() + ".");
            b.getPeople().push(defector);
        }
        System.out.println("");
    }

    // land a spaceship on a moon
    public static void land(Moon a, Spaceship b) { land(b, a); }

    // 
    public static void land(Spaceship a, Spaceship b) { land((Entity)a, (Entity)b);}

    // catch-all land(): do nothing
    public static void land(Entity a, Entity b) { }
}
