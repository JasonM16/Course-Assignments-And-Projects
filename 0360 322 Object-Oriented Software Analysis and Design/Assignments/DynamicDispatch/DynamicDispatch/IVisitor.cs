namespace A3Test
{
    public interface IVisitor
    {
        void Visit(Asteroid astereoid);
        void Visit(Spaceship spaceship);
        void Visit(Moon moon);
    }
}
