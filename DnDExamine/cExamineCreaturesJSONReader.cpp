// Evan Sinasac
// cExamineCreaturesJSONReader.cpp description:
//							This is the cpp file for the reader, the idea of this application is to make gathering
//							the specific information for my WoL Examine ability easier to parse by having JSON files
//							of every creature, when the user (me) inputs a creature's name, this reader opens the
//							corresponding file, loads the information into a structure that is passed back to the user
//							and the level of information required is printed to the screen

#include "cExamineCreaturesJSONReader.h"
#include <iostream>
#include <sstream>

cExamineCreatureJSONReader::cExamineCreatureJSONReader()
{

}

cExamineCreatureJSONReader::~cExamineCreatureJSONReader()
{

}

bool cExamineCreatureJSONReader::readCreatureFile(const std::string& filePath, Creature* currentCreature)
{
	using namespace rapidjson;

	FILE* fp = 0;
	fopen_s(&fp, filePath.c_str(), "rb");		// non-Windows use "r"

	if (!fp)
	{
		std::cout << "File didn't open, likely doesn't exist!" << std::endl;
		return false;
	}

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document d;
	d.ParseStream(is);

	if (d.HasParseError())
	{
		std::cout << "Uh oh, failed to parse JSON file!" << std::endl;
		return false;
	}

	if (!d["Name"].IsString())
	{
		std::cout << "Name doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->name = d["Name"].GetString();
	}

	if (!d["Creature Type"].IsString())
	{
		std::cout << "Creature Type doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->creatureType = d["Creature Type"].GetString();
	}

	if (!d["Max HP"].IsInt())
	{
		std::cout << "Max HP doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->maxHP = d["Max HP"].GetInt();
	}

	if (!d["Movement Speeds"].IsObject())
	{
		std::cout << "Movement Speeds doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Movement Speeds"]["Number"].IsInt())
		{
			std::cout << "Movement Speeds->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfSpeeds = d["Movement Speeds"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfSpeeds; i++)
			{
				std::stringstream ss;
				ss << "Type " << counter;
				if (!d["Movement Speeds"][ss.str().c_str()].IsString())
				{
					std::cout << "Movement Speeds->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->movementType.push_back(d["Movement Speeds"][ss.str().c_str()].GetString());
				}

				ss.str("");
				ss << "Speed " << counter;

				if (!d["Movement Speeds"][ss.str().c_str()].IsInt())
				{
					std::cout << "Movement Speeds->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->movementSpeed.push_back(d["Movement Speeds"][ss.str().c_str()].GetInt());
				}

				counter++;
			}
		}
	}

	if (!d["Challenge Rating"].IsString())
	{
		std::cout << "Challenge Rating doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->challengeRating = d["Challenge Rating"].GetString();
	}

	if (!d["EXP"].IsInt())
	{
		std::cout << "EXP doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->EXP = d["EXP"].GetInt();
	}

	if (!d["Skills"].IsObject())
	{
		std::cout << "Skills doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Skills"]["Number"].IsInt())
		{
			std::cout << "Skills->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfSkills = d["Skills"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfSkills; i++)
			{
				std::stringstream ss;
				ss << "Skill " << counter;

				if (!d["Skills"][ss.str().c_str()].IsString())
				{
					std::cout << "Skills->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->skills.push_back(d["Skills"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Senses"].IsObject())
	{
		std::cout << "Senses doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Senses"]["Number"].IsInt())
		{
			std::cout << "Senses->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfSenses = d["Senses"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfSenses; i++)
			{
				std::stringstream ss;
				ss << "Sense " << counter;

				if (!d["Senses"][ss.str().c_str()].IsString())
				{
					std::cout << "Senses->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->senses.push_back(d["Senses"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Languages"].IsObject())
	{
		std::cout << "Languages doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Languages"]["Number"].IsInt())
		{
			std::cout << "Languages->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfLanguages = d["Languages"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfLanguages; i++)
			{
				std::stringstream ss;
				ss << "Language " << counter;

				if (!d["Languages"][ss.str().c_str()].IsString())
				{
					std::cout << "Languages->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->languages.push_back(d["Languages"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Equipment Actions"].IsObject())
	{
		std::cout << "Equipment Actions doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Equipment Actions"]["Number"].IsInt())
		{
			std::cout << "Equipment Actions->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfSkills = d["Equipment Actions"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfSkills; i++)
			{
				std::stringstream ss;
				ss << "Action " << counter;

				if (!d["Equipment Actions"][ss.str().c_str()].IsString())
				{
					std::cout << "Equipment Actions->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->equipmentActions.push_back(d["Equipment Actions"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Other Actions"].IsObject())
	{
		std::cout << "Other Actions doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Other Actions"]["Number"].IsInt())
		{
			std::cout << "Other Actions->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfOtherActions = d["Other Actions"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfOtherActions; i++)
			{
				std::stringstream ss;
				ss << "Action " << counter;

				if (!d["Other Actions"][ss.str().c_str()].IsString())
				{
					std::cout << "Other Actions->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->otherActions.push_back(d["Other Actions"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["AC"].IsInt())
	{
		std::cout << "AC doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->AC = d["AC"].GetInt();
	}

	if (!d["Stats"].IsObject() || !d["Stats"]["Strength"].IsInt() || !d["Stats"]["Dexterity"].IsInt() ||
		!d["Stats"]["Constitution"].IsInt() || !d["Stats"]["Intelligence"].IsInt() || 
		!d["Stats"]["Wisdom"].IsInt() || !d["Stats"]["Charisma"].IsInt())
	{
		std::cout << "One of the stats doesn't exist!   AHHHHHHHH!" << std::endl;
		return false;
	}
	else
	{
		currentCreature->stats[0] = d["Stats"]["Strength"].GetInt();
		currentCreature->stats[1] = d["Stats"]["Dexterity"].GetInt();
		currentCreature->stats[2] = d["Stats"]["Constitution"].GetInt();
		currentCreature->stats[3] = d["Stats"]["Intelligence"].GetInt();
		currentCreature->stats[4] = d["Stats"]["Wisdom"].GetInt();
		currentCreature->stats[5] = d["Stats"]["Charisma"].GetInt();
	}

	if (!d["Abilities"].IsObject())
	{
		std::cout << "Abilities doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Abilities"]["Number"].IsInt())
		{
			std::cout << "Abilities->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfAbilities = d["Abilities"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfAbilities; i++)
			{
				std::stringstream ss;
				ss << "Ability " << counter;

				if (!d["Abilities"][ss.str().c_str()].IsString())
				{
					std::cout << "Abilities->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->abilities.push_back(d["Abilities"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Damage Resistances"].IsObject())
	{
		std::cout << "Damage Resistances doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Damage Resistances"]["Number"].IsInt())
		{
			std::cout << "Damage Resistances->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfDamageResistance = d["Damage Resistances"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfDamageResistance; i++)
			{
				std::stringstream ss;
				ss << "Damage " << counter;

				if (!d["Damage Resistances"][ss.str().c_str()].IsString())
				{
					std::cout << "Damage Resistances->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->damageResistances.push_back(d["Damage Resistances"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Damage Immunities"].IsObject())
	{
		std::cout << "Damage Immunities doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Damage Immunities"]["Number"].IsInt())
		{
			std::cout << "Damage Immunities->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfDamageResistance = d["Damage Immunities"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfDamageResistance; i++)
			{
				std::stringstream ss;
				ss << "Damage " << counter;

				if (!d["Damage Immunities"][ss.str().c_str()].IsString())
				{
					std::cout << "Damage Immunities->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->damageImmunities.push_back(d["Damage Immunities"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Condition Immunities"].IsObject())
	{
		std::cout << "Condition Immunities doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Condition Immunities"]["Number"].IsInt())
		{
			std::cout << "Condition Immunities->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfConditionResistance = d["Condition Immunities"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfConditionResistance; i++)
			{
				std::stringstream ss;
				ss << "Condition " << counter;

				if (!d["Condition Immunities"][ss.str().c_str()].IsString())
				{
					std::cout << "Condition Immunities->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->conditionImmunities.push_back(d["Condition Immunities"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Legendary Actions"].IsObject())
	{
		std::cout << "Legendary Actions doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Legendary Actions"]["Number"].IsInt())
		{
			std::cout << "Legendary Actions->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfDamageResistance = d["Legendary Actions"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfDamageResistance; i++)
			{
				std::stringstream ss;
				ss << "Action " << counter;

				if (!d["Legendary Actions"][ss.str().c_str()].IsString())
				{
					std::cout << "Legendary Actions->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->legendaryActions.push_back(d["Legendary Actions"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}

	if (!d["Lair Actions"].IsObject())
	{
		std::cout << "Lair Actions doesn't exist!" << std::endl;
		return false;
	}
	else
	{
		if (!d["Lair Actions"]["Number"].IsInt())
		{
			std::cout << "Lair Actions->Number doesn't exist!" << std::endl;
			return false;
		}
		else
		{
			int numberOfDamageResistance = d["Lair Actions"]["Number"].GetInt();
			int counter = 1;
			for (unsigned int i = 0; i < numberOfDamageResistance; i++)
			{
				std::stringstream ss;
				ss << "Action " << counter;

				if (!d["Lair Actions"][ss.str().c_str()].IsString())
				{
					std::cout << "Lair Actions->" << ss.str() << " doesn't exist!" << std::endl;
					return false;
				}
				else
				{
					currentCreature->lairActions.push_back(d["Lair Actions"][ss.str().c_str()].GetString());
				}

				counter++;
			}
		}
	}


	fclose(fp);
	return true;
}  // end of readCreatureFile