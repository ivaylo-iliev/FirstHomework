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

void Task::initialize_menu(std::string header_value)
{
	menu->set_header(header_value);
	menu->add_entry("Manual values.");
	menu->add_entry("Random values.");
	menu->add_entry("Back to main menu.");
}

void Task::execute()
{
	int choice = 0;
	do
	{
		Util::clear_screen();
		std::cout << *this->menu;
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			show_invalid_input_message();
		}
		else 
		{
			if (choice == menu->get_max_index() -1) 
			{
				break;
			}

			std::cout << std::endl;

			switch (choice)
			{
			case 1:
				manual_items();
				Util::pause(true);
				Util::clear_screen();
				continue;

			case 2:
				random_items();
				Util::pause(true);
				Util::clear_screen();
				continue;
			default :
				show_invalid_input_message();
				Util::pause(true);
				Util::clear_screen();
				continue;
			}
		}

	} while (choice != menu->get_max_index()-1);
}
void Task::manual_items(){}
void Task::random_items(){}

void Task::show_invalid_input_message()
{
	std::cout << "Invalid input. Please select value between 1 and " << menu->get_max_index() << std::endl;
	std::cout << menu->get_max_index() << " returns to main menu." << std::endl;
}

