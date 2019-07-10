

namespace A3Test
{
    public class CollidesWithVisitor : IVisitor
    {

        private readonly SpaceEntity _secondEntity;

        public CollidesWithVisitor(SpaceEntity secondEntity) => _secondEntity = secondEntity;

        public void Visit(Asteroid astereoid) => Interaction.Collide(_secondEntity, astereoid);

        public void Visit(Spaceship spaceship) => Interaction.Collide(_secondEntity, spaceship);

        public void Visit(Moon moon) => Interaction.Collide(_secondEntity, moon);
    }
}
