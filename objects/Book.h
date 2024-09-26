#pragma once

#include <iostream>

class Book {
private:
	std::string author_namr; 
	std::string book_title;
	std::string publisher_name;
	int publication_year;
public:
	std::string get_author_name();
	void set_author_name(std::string);

	std::string get_book_title();
	void set_book_title(std::string);

	std::string get_publisher_name();
	void set_publisher_name(std::string);

	int get_publication_year();
	void set_publication_yeat(int);

	bool check_publication_year(int);

	bool operator==(const Book& rhs);

	friend std::ostream& operator<<(std::ostream& stream, const Book& book);
	friend std::istream& operator>>(std::istream& stream, Book& book);
};