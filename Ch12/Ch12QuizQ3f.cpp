#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:

	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type type, const std::string& name, const std::string& roar, int hitPoints)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
	{}
	std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case Type::dragon: return "dragon";
		case Type::goblin: return "goblin";
		case Type::ogre: return "ogre";
		case Type::orc: return "orc";
		case Type::skeleton: return "skeleton";
		case Type::troll: return "troll";
		case Type::vampire: return "vampire";
		case Type::zombie: return "zombie";
		default: return "???";
		}
	}

	void print() const
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}

	friend class MonsterGenerator;		//This isn't necessary. The generateMonster function creates an object of the 
};										//Monster class. It doesn't need access to specific functions within the class

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		return{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
		/*	static Monster a;
		a.m_type = Monster::Type::skeleton;		//Ok, if I create the object this way (with '='), I get an error about no default
		a.m_name = "Bones";						//constructor, which only goes away if I comment out the constructor in the
		a.m_roar = "*rattle*";					//Monster class. But once I do that, this syntax actually works so it's weird.
		a.m_hitPoints = 4;						//Although, frankly, props to me for being fairly quick to figure out how to get
		return a;*/								//the function to return multiple values
	}
};

int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}