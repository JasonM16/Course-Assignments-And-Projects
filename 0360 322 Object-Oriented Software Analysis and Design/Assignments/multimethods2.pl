use v6;                                             # This is a Perl6 program

#------------------------------------------------------------------------------
# define a class hierarchy...
#------------------------------------------------------------------------------

class Entity { }                                    # abstract base class

class Asteroid is Entity {
  has Str $.matter;                                     # what is this asteroid made of?
}

class SpaceShip is Entity {
  has Str $.name;                                       # name of ship
  has Str @.passengers;                                 # names of the passengers
}

class Moon is Entity {
  has Str $.name;                                       # name of moon
  has Str @.people;                                     # people on moon
}

#------------------------------------------------------------------------------
# define collide multimethods...
#------------------------------------------------------------------------------

# collide two asteroids...
multi sub collide(Asteroid $a, Asteroid $b) {
  say "Collision between asteroid {$a.matter} and asteroid {$b.matter}.";
}

# collide an asteroid and a spaceship
multi sub collide(Asteroid $a, SpaceShip $b) {
  say "Collision between spaceship {$a.matter} and asteroid {$b.name}.";
}

# collide a spaceship and an asteroid
multi sub collide(SpaceShip $a, Asteroid $b) {
  collide($b, $a);                                   # reverse the arguments
}

# collide two spaceships
multi sub collide(SpaceShip $a, SpaceShip $b) {
  print "Catastrophic collision between spaceship {$a.name} and spaceship {$b.name}.";

	# Concatenate together the lists of passengers. No survivors.
  my @corpses = flat $a.passengers, $b.passengers;
	
	# Only print this if the array size is non-zero.
  print " Casualties: " if @corpses.elems > 0;
	
  # Print the casualties.
  @corpses.print;
	
  # Assign the arrays to empty.
  $a.passengers = $b.passengers = [];
  say "";                                             # output newline
}

# collide a spaceship and a moon
multi sub collide(SpaceShip $a, Moon $b) {
  print "Catastrophic collision between spaceship {$a.name} and moon {$b.name}.";

  my @corpses = $a.passengers;

	# pop a person from the moon's population and push it into the list of
	# people who will be vanquished. Only do this if there is someone left
	# to pop...
  @corpses.push($b.people.pop) if $b.people.elems > 0;

  print " Casualties: " if @corpses.elems > 0;
  @corpses.print;
  $a.passengers = [];
  say "";                                             # output newline
}

# collide a moon and a spaceship
multi sub collide(Moon $a, SpaceShip $b) {
  collide($b, $a);                                   # reverse the arguments
}

# catch-all collide(): do nothing
multi sub collide(Entity $a, Entity $b) { }         # all other objects colliding: do nothing

#------------------------------------------------------------------------------
# define land multimethods...
#------------------------------------------------------------------------------

# land a spaceship on an asteroid
multi sub land(SpaceShip $a, Asteroid $b) {
  print "Spaceship {$a.name} landed on asteroid made up of {$b.matter}.";
  if $a.passengers.elems > 0 {
    print "  The passengers [{$a.passengers}] pick up some {$b.matter}.";
  } 
  say "";                                         # output newline
}

# land a spaceship on an asteroid
multi sub land(Asteroid $a, SpaceShip $b) {
  land($b, $a);                                      # reverse the arguments
}

# land a spaceship on a moon
multi sub land(SpaceShip $a, Moon $b) {
  print "Spaceship {$a.name} landed on moon {$b.name}.";
  
  if $a.passengers.elems > 0 {
    my $defector = $a.passengers.pop;

		# The tilta ~ is the string concatenation operator.
    print " {$defector} has left the spaceship {$a.name}, " 
      ~ "and is setting up a farm on the moon {$b.name}";
	
	  # Add the defector to the moon people.		
    $b.people.push($defector);
  }
  say "";                                             # output newline
}

# land a spaceship on a moon
multi sub land(Moon $a, SpaceShip $b) {
  land($b, $a);                                      # reverse the arguments
}

# catch-all land(): do nothing
multi sub land(Entity $a, Entity $b) { }            # all other objects landing: do nothing

#------------------------------------------------------------------------------
# demonstrate abstract multimethod 
# (double dispatch) function invocation
#------------------------------------------------------------------------------

sub execute-collisions(Entity @things-to-destroy)
{
  # Execute the loop body 6 times.
  for ^6 {
		# Pick two elements from the array.
    my @things = @things-to-destroy.pick(2);
		# Smash them together!
    collide(@things[0], @things[1]);
  }
}

sub execute-landings(Entity @things-to-conquer)
{
  # Execute the loop body 6 times.
  for ^6 {
    # Pick two elements from the array.
    my @things = @things-to-conquer.pick(2);
		# Land one onto the other!
    land(@things[0], @things[1]);
  }
}

#------------------------------------------------------------------------------
# define main program...
#------------------------------------------------------------------------------

sub MAIN {
  # create an Entity array of some asteroids, spaceships, and moons
  my Entity @objects = (
    Asteroid.new(matter => 'rock');
    Asteroid.new(matter => 'ice and dirt');
    SpaceShip.new(name => 'Relativity', passengers => ['Mr. X', 'Ms. Y']);
    SpaceShip.new(name => 'Endaevour', passengers => ['Mr. Q', 'Ms. R']);
    Moon.new(name => 'Phobos', people => ['Mr. M', 'Ms. N']);
    Moon.new(name => 'Deimos', people => ['Mr. J', 'Ms. K']);
  );

  # randomly apply collisions
  execute-collisions(@objects);

  say "------------------------------------------";

  # create an Entity array of some asteroids, spaceships, and moons
  @objects = (
    Asteroid.new(matter => 'diamond');
    Asteroid.new(matter => 'uranium');
    SpaceShip.new(name => 'Andromeda', passengers => ['Qbert', 'Marvin']);
    SpaceShip.new(name => 'Steve', passengers => ['Pacman', 'Inky']);
    Moon.new(name => 'Phobos', people => ['Croft', 'Jones']);
    Moon.new(name => 'Deimos', people => ['Neo', 'Trinity']);
  );

  # randomly apply landings
  execute-landings(@objects);
}
