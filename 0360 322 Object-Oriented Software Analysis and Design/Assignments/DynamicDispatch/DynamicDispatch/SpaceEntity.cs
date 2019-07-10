
using System.Collections.Generic;

namespace A3Test
{
    public abstract class SpaceEntity
    {
        public abstract void Accept(IVisitor visitor);
    }
}
