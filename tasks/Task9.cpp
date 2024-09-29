#include "Task9.h"
#include "faker-cxx/book.h"
#include "Util.h"

Task9::Task9(std::string header_value)
{
    this->initialize_menu(header_value);
}

Task9::~Task9()
{
}

void Task9::manual_items()
{
    Book* first_book = new Book();

    std::cout << "Enter first book details: " << std::endl;
    std::cin >> *first_book;
    std::cout << *first_book;

    int publication_year_check;
    std::cout << std::endl << "Enter year to check if the book was published before:";
    std::cin >>publication_year_check;

    std::string is_published_before_answer = first_book->is_published_before(publication_year_check) ? "Yes" : "No";
    std::cout << "Was it published before " << publication_year_check <<"? " << is_published_before_answer << std::endl;

    Book* second_book = new Book();
    std::cout << "Enter second book details: " << std::endl;
    std::cin >> *second_book;

    std::cout << "Are they the same book? " << (*first_book == *second_book ? "Yes" : "No") << std::endl;

    delete first_book;
    delete second_book;
}

void Task9::random_items()
{
    int current_year = Util::get_current_year();
    int publication_year_check = Util::random_int(1900, current_year);

    Book* first_book = init_random_book(current_year);
    std::cout << "First book:" << std::endl;
    std::cout << *first_book << std::endl;
    std::cout << "Was it published before " << publication_year_check <<"? " << (first_book->is_published_before(publication_year_check) ? "Yes" : "No") << std::endl;

    Book* second_book = init_random_book(current_year);
    std::cout << "Second book:" << std::endl;
    std::cout << *second_book << std::endl;
    std::cout << "Was it published before " << publication_year_check <<"? " << (second_book->is_published_before(publication_year_check) ? "Yes" : "No") << std::endl;

    std::cout << "Are they the same book? " << (*first_book == *second_book ? "Yes" : "No") << std::endl;

    delete first_book;
    delete second_book;
}

Book* Task9::init_random_book(int current_year)
{
    const auto title =  faker::book::title();
    const auto author_name = faker::book::author();
    const auto publisher_name = faker::book::publisher();

    Book* book = new Book();
    book->set_book_title({title.begin(), title.end()});
    book->set_author_name({author_name.begin(), author_name.end()});
    book->set_publisher_name({publisher_name.begin(), publisher_name.end()});
    book->set_publication_year(Util::random_int(1900, current_year));

    return book;
}



