#pragma once
#include <string>
#include <vector>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>

// Template of JSON files
//		All vector sized information types should and will be at least of size 1, to at least say N/A,
//		Everything else is just a string or int
struct Creature
{
	std::string name;
	std::string creatureType;
	int maxHP;
	std::vector<std::string> movementType;
	std::vector<int> movementSpeed;
	std::string challengeRating;
	int EXP;
	std::vector<std::string> skills;
	std::vector<std::string> senses;
	std::vector<std::string> languages;
	std::vector<std::string> equipmentActions;
	std::vector<std::string> otherActions;
	int AC;
	int stats[6];
	std::vector<std::string> abilities;
	std::vector<std::string> damageResistances;
	std::vector<std::string> damageImmunities;
	std::vector<std::string> conditionImmunities;
	std::vector<std::string> legendaryActions;
	std::vector<std::string> lairActions;
};

class cExamineCreatureJSONReader
{
private:

public:
	cExamineCreatureJSONReader();
	~cExamineCreatureJSONReader();

	bool readCreatureFile(const std::string& filePath, Creature* currentCreature);
};