#pragma once

#include <iostream>

class Book {
private:
	std::string authorName;
	std::string title;
	std::string publisherName;
	int publicationYear;
public:
	std::string getAuthorName();
	void setAuthorName(std::string);

	std::string getBookTitle();
	void setBookTitle(std::string);

	std::string getPublisherName();
	void setPublisherName(std::string);

	int getPublicationYear();
	void setPublicationYear(int);

	bool isPublishedBefore(int);

	friend bool operator==(const Book&, const Book&);
	friend std::ostream& operator<<(std::ostream& stream, const Book& book);
	friend std::istream& operator>>(std::istream& stream, Book& book);
};
