public class LandsOnVisitor extends EntityVisitor {

    // second argument
    private Entity secondEntity;

    LandsOnVisitor(Entity secondEntity) {               // construct, remember second argument
        this.secondEntity = secondEntity;
    }

    public void visit(Asteroid a) {                     // asteroid lands on a ...??
        secondEntity.doLand(a);                         // determine what secondEntity is
    }

    public void visit(Spaceship s) {                    // spaceship lands on a ...??
        secondEntity.doLand(s);                         // determine what secondEntity is
    }

    public void visit(Moon m) {                         // moon lands on a ...??
        secondEntity.doLand(m);                         // determine what secondEntity is
    }
}
