using System;


namespace A3Test
{
    public class LandsOnVisitor : IVisitor
    {
        private readonly SpaceEntity _secondEntity;

        public LandsOnVisitor(SpaceEntity secondEntity) => _secondEntity = secondEntity;

        public void Visit(Asteroid astereoid) => Interaction.Land(_secondEntity, astereoid);

        public void Visit(Spaceship spaceship) => Interaction.Land(_secondEntity, spaceship);

        public void Visit(Moon moon) => Interaction.Land(_secondEntity, moon);
    }
}
