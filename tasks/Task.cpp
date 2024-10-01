#include "Task.h"
#include "Menu.h"
#include "Util.h"
#include <iostream>
#include <limits>
#include <cstdlib>

Task::Task()
{
	menu = new Menu();
}

Task::~Task()
{
	delete menu;
}

void Task::initializeMenu(std::string header_value)
{
	menu->setHeader(header_value);
	menu->addEntry("Manual values.");
	menu->addEntry("Random values.");
	menu->addEntry("Back to main menu.");
}

void Task::execute()
{
	int choice = 0;
	do
	{
		Util::clearScreen();
		std::cout << *this->menu;
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			showInvalidInputMessage();
		}
		else 
		{
			if (choice == menu->getMaxIndex() -1) 
			{
				break;
			}

			std::cout << std::endl;

			switch (choice)
			{
			case 1:
				manualItems();
				Util::pause(true);
				Util::clearScreen();
				continue;

			case 2:
				randomItems();
				Util::pause(true);
				Util::clearScreen();
				continue;
			default :
				showInvalidInputMessage();
				Util::pause(true);
				Util::clearScreen();
				continue;
			}
		}

	} while (choice != menu->getMaxIndex()-1);
}
void Task::manualItems(){}
void Task::randomItems(){}

void Task::showInvalidInputMessage()
{
	std::cout << "Invalid input. Please select value between 1 and " << menu->getMaxIndex() << std::endl;
	std::cout << menu->getMaxIndex() << " returns to main menu." << std::endl;
}

