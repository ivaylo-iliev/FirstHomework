#pragma once
#include "Task.h"
#include "Book.h"

class Task9 : public Task
{
private:
	Book* init_random_book(int current_year);
public:
    Task9(std::string header_value);
	~Task9();
	void manual_items();
	void random_items();
};
