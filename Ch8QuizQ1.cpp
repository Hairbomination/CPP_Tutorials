#include<iostream>
#include<string>

enum class Monster
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

struct Attributes
{
	std::string name;
	int health;
	Monster species;
};

void printMonster(Attributes x)
{
	if (x.species == Monster::ogre)
		std::cout << "This Ogre is named " << x.name << " and has " << x.health << " health.\n";
	else
		std::cout << "This Slime is named " << x.name << " and has " << x.health << " health.\n";
}

int main()
{
	Attributes ogre{ "Torg", 145, Monster::ogre };
	Attributes slime{ "Blurp", 23, Monster::slime };
	printMonster(ogre);
	printMonster(slime);

	return 0;
}