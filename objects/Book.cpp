#include "Book.h"
#include "Util.h"
#include <iomanip>

std::string Book::getAuthorName()
{
    return this->authorName;
}

void Book::setAuthorName(std::string value)
{
    this->authorName = value;
}

std::string Book::getBookTitle()
{
    return this->title;
}

void Book::setBookTitle(std::string value)
{
    this->title = value;
}

std::string Book::getPublisherName()
{
    return this->publisherName;
}

void Book::setPublisherName(std::string value)
{
    this->publisherName = value;
}

int Book::getPublicationYear()
{
    return this->publicationYear;
}

void Book::setPublicationYear(int value)
{
    this->publicationYear = value;
}

bool operator==(const Book& lhs, const Book& rhs)
{

    bool titles_are_equal = false;
    bool authors_are_equal = false;
    bool publishers_are_equal = false;
    bool publication_years_are_equal = false;

    if(Util::toLower(Util::trim(rhs.title)) == Util::toLower(Util::trim(lhs.title)))
    {
        titles_are_equal = true;
    }

    if(Util::toLower(Util::trim(rhs.authorName))  == Util::toLower(Util::trim(lhs.authorName)))
    {
        authors_are_equal = true;
    }

    if(Util::toLower(Util::trim(lhs.publisherName)) == Util::toLower(Util::trim(rhs.publisherName)))
    {
        publishers_are_equal = true;
    }

    if(lhs.publicationYear == rhs.publicationYear)
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
    stream << std::left << std::setw(label_column_width) << "Author:" << book.authorName << std::endl;
    stream << std::left << std::setw(label_column_width) << "Publisher:" << book.publisherName << std::endl;
    stream << std::left << std::setw(label_column_width) << "Publication year:" << book.publicationYear;
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

    book.setBookTitle(title);
    book.setAuthorName(author_name);
    book.setPublisherName(publisher_name);
    book.setPublicationYear(publication_year);

    return stream;
}

bool Book::isPublishedBefore(int year)
{
    return this->getPublicationYear() < year;
}
