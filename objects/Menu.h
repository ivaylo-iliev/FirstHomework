#pragma once
#include <vector>
#include <iomanip>

#include "MenuEntry.h"

constexpr int MAX_HEADER_WIDTH = 80;
constexpr int MAX_HEADER_LINE_LENGTH = 60;
constexpr char HEADER_BORDER_CHAR = '=';
constexpr int HEADER_BORDER_WIDTH = 2;
constexpr int MENU_FORCE_EXIT = 999;

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
