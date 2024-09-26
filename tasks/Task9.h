#pragma once
#include "Task.h"
#include "Book.h"

class Task9 : public Task
{
private:
    Book book;
public:
    Task8(std::string header_value);
	~Task8();
	void manual_items();
	void random_items();
}