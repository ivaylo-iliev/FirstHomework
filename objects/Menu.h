#pragma once
#include <vector>
#include <iomanip>

#include "MenuEntry.h"

const int MAX_HEADER_WIDTH = 80;
const int MAX_HEADER_LINE_LENGTH = 60;
const char HEADER_BORDER_CHAR = '=';
const int HEADER_BORDER_WIDTH = 2;
const int MENU_FORCE_EXIT = 999;

class Menu
{
private:
	std::vector<MenuEntry> menuEntries;
	std::vector<std::string> headerLines;
	int maxIndex;
	int choice;

public: 
	Menu();
	~Menu();
	void addEntry(std::string);
	const std::vector<MenuEntry> &getEntries() const;
	void setHeader(std::string);
	int getMaxIndex();
	friend std::ostream& operator<<(std::ostream& stream, const Menu& menu);
};
