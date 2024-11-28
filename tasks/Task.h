#pragma once
#include "Menu.h"

class Task
{
private:
	virtual void manualItems();
	virtual void randomItems();
	void showInvalidInputMessage();

protected:
	Menu* menu;

public:
	Task();
	~Task();
	virtual void initializeMenu(std::string);
	virtual void execute();	
};

