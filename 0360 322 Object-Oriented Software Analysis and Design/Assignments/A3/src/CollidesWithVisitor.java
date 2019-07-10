public class CollidesWithVisitor extends EntityVisitor {

    // second argument
    private Entity secondEntity;

    CollidesWithVisitor(Entity secondEntity) {          // construct, remember second argument
        this.secondEntity = secondEntity;
    }

    public void visit(Asteroid asteroid) {              // asteroid colliding with a ...??
        secondEntity.doCollision(asteroid);             // determine what secondEntity is
    }
    public void visit(Spaceship spaceship) {            // spaceship colliding with a ...??
        secondEntity.doCollision(spaceship);            // determine what secondEntity is
    }
    public void visit(Moon moon) {                      // moon colliding with a ...??
        secondEntity.doCollision(moon);                 // determine what secondEntity is
    }
}
