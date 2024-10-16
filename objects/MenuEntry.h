#pragma once
#include <string>
#include <iomanip>

const int INDEX_WIDTH = 3;
const int SEPARATOR_WIDTH = 1;
const char SEPARATOR = ' ';
const char POINT = '.';

class MenuEntry
{
private:
	int index = 0;
	std::string label;

public:
	void setIndex(int);
	const int& getIndex() const;
	void setLabel(std::string);
	const std::string& getLabel() const;
};

std::ostream& operator<<(std::ostream& stream, const MenuEntry& entry);

