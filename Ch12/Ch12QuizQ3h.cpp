#include <iostream>
#include <string>
#include <string_view>
#include <ctime>
#include <cstdlib>
#include <array>

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
	{

	}

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
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		static std::array s_names{ "James Deathbringer", "Hexifan", "Azubian", "Jhiddar the Degenerate", "Ovnacht Mort", "Rancid Bloodborne" };
		static std::array s_roars{ "caw", "cackle", "screech", "scream", "hoot", "wail" };
		return { static_cast<Monster::Type>(getRandomNumber(0, (static_cast<int>(Monster::Type::max_monster_types)-1))), s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], getRandomNumber(1, 100) };
	}
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
		return static_cast<int>((max - min + 1) * (std::rand() * fraction)) + min;
	}
};

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}