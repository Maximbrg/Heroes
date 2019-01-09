prog: Archer.o Assignment5.o BlackDragon.o Creature.o Hero.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o
	c++ Archer.o Assignment5.o BlackDragon.o Creature.o Hero.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o -o Heroes
Archer.o: Archer.o
	c++ -c Archer.cpp Archer.h Creature.h
Assignment5.o: Assignment5.o
	c++ -c Assignment5.cpp Hero.h Warrior.h Thief.h Necromancer.h Error.h
BlackDragon.o: BlackDragon.o
	c++ -c BlackDragon.cpp BlackDragon.h Creature.h
Creature.o: Creature.o
	c++ -c Creature.cpp Creature.h
Hero.o: Hero.o
	c++ -c Hero.h Hero.cpp Creature.h BlackDragon.h Vampire.h Wizard.h Archer.h Zombie.h Error.h
Necromancer.o: Necromancer.o
	c++ -c Necromancer.cpp Necromancer.h Hero.h
Thief.o: Thief.o
	c++ -c Thief.cpp Thief.h Hero.h
Vampire.o: Vampire.o
	c++ -c Vampire.cpp Vampire.h Creature.h
Warrior.o: Warrior.o
	c++ -c Warrior.cpp Warrior.h Hero.h
Wizard.o: Wizard.o
	c++ -c Wizard.cpp Wizard.h Creature.h
Zombie.o: Zombie.o
	c++ -c Zombie.cpp Zombie.h Creature.h
clean:
	rm -f *.o
