#include <iostream>
#include <string>

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
	int m_hPoints{};

public:
	Monster(Type type, std::string name, std::string roar, int hPoints)		//For the last f*ing time, pass the strings by const reference!!
		: m_type{type}, m_name{name}, m_roar{roar}, m_hPoints{hPoints}
	{}
	std::string getTypeString(const Type type)		//std::string view (don't forget to include the header). 
	{							//I remembered to const, but it should've been a const function rather than const parameter
		switch (type)
		{
		case Type::dragon:   return "dragon";		case Type::goblin: return "goblin";
		case Type::ogre:     return "ogre";		case Type::orc:	   return "orc";
		case Type::skeleton: return "skeleton";		case Type::troll:  return "troll";
		case Type::vampire:  return "vampire";		case Type::zombie: return "zombie";
		default: return "Unknown";
		}
	}
	void print()		//Also should be a const function
	{
		std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hPoints << " hit points and says " <<
			m_roar << '\n';			//Didn't need to pass m_type to getTypeString. It can already access m_type
	}
};

int main()
{
	Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	return 0;
}
