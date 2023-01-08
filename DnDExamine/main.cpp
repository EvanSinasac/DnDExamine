// Evan Sinasac
// DnDExamine
//		Honestly, idk why I'm doing this other than to practice making a JSON reader and configuration files.
//		Like, I'm going to have the stat blocks up whenever the player uses examine, but I had this thought the other day
//		and thought it could be kinda fun to make
//		I guess I could also make a distribution version at some point and give it to the player and they can use it themselves
//		but otherwise it'll just be me lmao
//		Anyways, uses the console to receive the name of the creature being examined, then opens the corresponding JSON file
//		and prints out the relevant information according to the level of Examine.

#include "cExamineCreaturesJSONReader.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

int main(int argv, char* argc)
{
	int examineLevel = 0;
	bool hi = true;
	std::string creatureName;
	std::stringstream ss;

	cExamineCreatureJSONReader jsonReader;

	std::cout << "Please enter the level of Examine: ";
	std::cin >> examineLevel;	// gunna trust the user here, anything other than a number should crash the program, or not idk

	while (hi)
	{
		std::cout << std::endl;

		std::cout << "Please enter the name of the creature you are examining: ";
		std::cin >> creatureName;

		std::cout << std::endl;

		std::transform(creatureName.begin(), creatureName.end(), creatureName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (creatureName == "exit")
		{
			hi = false;
		}
		else
		{

			ss.str("");
			ss << "Creatures\\" << creatureName << ".json";

			Creature* currentCreature = new Creature;
			if (!jsonReader.readCreatureFile(ss.str().c_str(), currentCreature))
			{
				std::cout << "That is not a creature I am familiar with.  Something horrible has occurred.  Please try again." << std::endl;
			}
			else
			{
				if (examineLevel >= 1)	// this should always happen but making it anyways for clarity
				{
					// Name, Creature Type, HP, Movement Speed, Challenge Rating, EXP
					std::cout << "Name: " << currentCreature->name << std::endl;
					std::cout << "Creature Type: " << currentCreature->creatureType << std::endl;
					std::cout << "Max HP: " << currentCreature->maxHP << std::endl;
					std::cout << "Movement Speeds: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->movementType.size(); index++)
					{
						std::cout << "      " << currentCreature->movementType[index] << ": " << currentCreature->movementSpeed[index] << std::endl;
					}
					std::cout << "Challenge Rating: " << currentCreature->challengeRating << " (" << currentCreature->EXP << " XP)" << std::endl;
				}

				if (examineLevel >= 2)
				{
					// Skills, Senses, Languages, Equipment Actions
					std::cout << "Skills: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->skills.size(); index++)
					{
						std::cout << "      " << currentCreature->skills[index] << std::endl;
					}
					std::cout << "Senses: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->senses.size(); index++)
					{
						std::cout << "      " << currentCreature->senses[index] << std::endl;
					}
					std::cout << "Languages: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->languages.size(); index++)
					{
						std::cout << "      " << currentCreature->languages[index] << std::endl;
					}
					std::cout << "Equipment Actions: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->equipmentActions.size(); index++)
					{
						std::cout << "      " << currentCreature->equipmentActions[index] << std::endl;
					}
				}

				if (examineLevel >= 3)
				{
					// Actions, AC, Stats
					std::cout << "Other Actions: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->otherActions.size(); index++)
					{
						std::cout << "      " << currentCreature->otherActions[index] << std::endl;
					}
					std::cout << "AC: " << currentCreature->AC << std::endl;
					std::cout << "Strength      Dexterity      Constitution      Intelligence      Wisdom      Charisma" << std::endl;
					std::cout << "   " << currentCreature->stats[0] <<
						"            " << currentCreature->stats[1] <<
						"               " << currentCreature->stats[2] <<
						"                " << currentCreature->stats[3] <<
						"             " << currentCreature->stats[4] <<
						"            " << currentCreature->stats[5] << std::endl;
				}

				if (examineLevel >= 4)
				{
					// Abilities, Damage Resistances
					std::cout << "Abilities: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->abilities.size(); index++)
					{
						std::cout << "      " << currentCreature->abilities[index] << std::endl;
					}
					std::cout << "Damage Resistances: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->damageResistances.size(); index++)
					{
						std::cout << "      " << currentCreature->damageResistances[index] << std::endl;
					}
				}

				if (examineLevel >= 5)
				{
					// Damage Immunities, Condition Immunities, Legendary Actions, Lair Actions
					std::cout << "Damage Immunities: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->damageImmunities.size(); index++)
					{
						std::cout << "      " << currentCreature->damageImmunities[index] << std::endl;
					}
					std::cout << "Condition Immunities: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->conditionImmunities.size(); index++)
					{
						std::cout << "      " << currentCreature->conditionImmunities[index] << std::endl;
					}
					std::cout << "Legendary Actions: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->legendaryActions.size(); index++)
					{
						std::cout << "      " << currentCreature->legendaryActions[index] << std::endl;
					}
					std::cout << "Lair Actions: " << std::endl;
					for (unsigned int index = 0; index != currentCreature->lairActions.size(); index++)
					{
						std::cout << "      " << currentCreature->lairActions[index] << std::endl;
					}
				}
			}

		}
	}

	std::cout << "Thank you!  Goodbye!" << std::endl;

	return 0;
}