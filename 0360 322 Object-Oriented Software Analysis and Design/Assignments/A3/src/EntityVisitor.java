public abstract class EntityVisitor {
    public abstract void visit(Asteroid a);
    public abstract void visit(Spaceship s);
    public abstract void visit(Moon m);
}
