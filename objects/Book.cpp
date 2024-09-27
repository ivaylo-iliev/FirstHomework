#include "Book.h"

std::string Book::get_author_name()
{
    return std::string();
}

void Book::set_author_name(std::string)
{
}

std::string Book::get_book_title()
{
    return std::string();
}

void Book::set_book_title(std::string)
{
}

std::string Book::get_publisher_name()
{
    return std::string();
}

void Book::set_publisher_name(std::string)
{
}

int Book::get_publication_year()
{
    return 0;
}

void Book::set_publication_yeat(int)
{
}

bool Book::check_publication_year(int)
{
    return false;
}

bool Book::operator==(const Book& rhs)
{
    return false;
}

std::ostream& operator<<(std::ostream& stream, const Book& book)
{
    return stream;
}

std::istream& operator>>(std::istream& stream, Book& book)
{
    return stream;
}
