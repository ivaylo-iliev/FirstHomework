#pragma once
#include "Task.h"
#include "Book.h"

class Task9 : public Task
{
private:
	Book* init_random_book(int headerValue);
public:
    Task9(std::string headerValue);
	~Task9();
	void manualItems();
	void randomItems();
};
