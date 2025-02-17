#include <iostream>
#include <limits>

#include "Util.h"
#include "Menu.h"
#include "Task.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"
#include "Task6.h"
#include "Task7.h"
#include "Task8.h"
#include "Task9.h"
#include "Task10.h"

int main()
{
	Menu* menu = new Menu();
	
	std::string header = "There are 26 tasks available. Details will be displayed on task selection. ";
	header += "Please make selection between 1 and 26. Value of 0 will exit the program.";

	menu->setHeader(header);
	std::vector<std::string> task_definitions = Util::readTaskDefinitions();

	int main_choice = 0;

	do
	{
		Util::clearScreen();
		Task* task = nullptr;

		std::cout << *menu;
		std::cin >> main_choice;
		

		if (std::cin.fail() || main_choice < 0 || main_choice > 26)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please select value between 1 and " << 26 << ". 0 exits the program." << std::endl;
		} 
		else if (main_choice > 0 && main_choice <= 26)
		{
			switch (main_choice)
			{
			case 1:
				task = new Task1(task_definitions[0]);
				break;
			case 2:
				task = new Task2(task_definitions[1]);
				break;
			case 3:
				task = new Task3(task_definitions[2]);
				break;
			case 4:
				task = new Task4(task_definitions[3]);
				break;
			case 5:
				task = new Task5(task_definitions[4]);
				break;
			case 6:
				task = new Task6(task_definitions[5]);
				break;
			case 7:
				task = new Task7(task_definitions[6]);
				break;
			case 8:
				task = new Task8(task_definitions[7]);
				break;
			case 9:
				task = new Task9(task_definitions[8]);
				break;
			case 10:
				task = new Task10(task_definitions[9]);
				break;
			default:
				break;
			}

			if(task != nullptr)
			{
				task->execute();
			}

			delete task;
		} 

		if (main_choice == 0)
		{
			std::cout << "Bye!" << std::endl;
			break;
		}
	
	} while (true);

	delete menu;
}
