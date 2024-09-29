#include "Book.h"
#include "Util.h"
#include <iomanip>

std::string Book::get_author_name()
{
    return this->author_name;
}

void Book::set_author_name(std::string value)
{
    this->author_name = value;
}

std::string Book::get_book_title()
{
    return this->title;
}

void Book::set_book_title(std::string value)
{
    this->title = value;
}

std::string Book::get_publisher_name()
{
    return this->publisher_name;
}

void Book::set_publisher_name(std::string value)
{
    this->publisher_name = value;
}

int Book::get_publication_year()
{
    return this->publication_year;
}

void Book::set_publication_year(int value)
{
    this->publication_year = value;
}

bool operator==(const Book& lhs, const Book& rhs)
{

    bool titles_are_equal = false;
    bool authors_are_equal = false;
    bool publishers_are_equal = false;
    bool publication_years_are_equal = false;

    if(Util::to_lower(Util::trim(rhs.title)) == Util::to_lower(Util::trim(lhs.title)))
    {
        titles_are_equal = true;
    }

    if(Util::to_lower(Util::trim(rhs.author_name))  == Util::to_lower(Util::trim(lhs.author_name)))
    {
        authors_are_equal = true;
    }

    if(Util::to_lower(Util::trim(lhs.publisher_name)) == Util::to_lower(Util::trim(rhs.publisher_name)))
    {
        publishers_are_equal = true;
    }

    if(lhs.publication_year == rhs.publication_year)
    {
        publication_years_are_equal = true;
    }

    if(titles_are_equal == true && authors_are_equal == true  && publishers_are_equal == true && publication_years_are_equal == true)
    {
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream& stream, const Book& book)
{
    int label_column_width = 18;
    stream << std::left << std::setw(label_column_width) << "Title:" << book.title << std::endl;
    stream << std::left << std::setw(label_column_width) << "Author:" << book.author_name << std::endl;
    stream << std::left << std::setw(label_column_width) << "Publisher:" << book.publisher_name << std::endl;
    stream << std::left << std::setw(label_column_width) << "Publication year:" << book.publication_year;
    stream << std::right;
    return stream;
}

std::istream& operator>>(std::istream& stream, Book& book)
{
    int label_column_width = 24;
    std::string title;
    std::string author_name;
    std::string publisher_name;
    int publication_year;

    std::cout << "Enter title: ";
    stream >> title;
    std::cout << "Enter author: ";
    stream >> author_name;
    std::cout << "Enter publisher: ";
    stream >> publisher_name;
    std::cout << "Enter publication year: ";
    stream >> publication_year;

    book.set_book_title(title);
    book.set_author_name(author_name);
    book.set_publisher_name(publisher_name);
    book.set_publication_year(publication_year);

    return stream;
}

bool Book::is_published_before(int year)
{
    return this->get_publication_year() < year;
}
