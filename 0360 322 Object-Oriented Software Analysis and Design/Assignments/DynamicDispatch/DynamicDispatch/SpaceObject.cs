using System.Collections.Generic;



namespace A3Test
{
    public class SpaceObject : SpaceEntity
    {
        public List<SpaceObject> Entities = new List<SpaceObject>();

        public override void Accept(IVisitor visitor)
        {
            foreach (var entity in Entities)
                entity.Accept(visitor);
        }
    }
}
