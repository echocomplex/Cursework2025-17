#include "Book.hxx"

Book::Book(void) noexcept {
    this->year = 0;
}

Book::Book(const std::string& author, const std::string& title, const unsigned short year, const std::string& category, const std::string& genre) noexcept {
    this->author = author;
    this->title = title;
    this->year = year;
    this->category = category;
    this->genre = genre;
}

Book& Book::operator=(const Book& unit) noexcept {
    this->author = unit.author;
    this->title = unit.title;
    this->year = unit.year;
    this->category = unit.category;
    this->genre = unit.genre;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Book& unit) {
    os << 
        unit.author << ", " <<
        unit.title << ", " <<
        unit.year << ", " <<
        unit.category << ", " <<
        unit.genre
    ;
    return os;
}

std::string Book::getAuthor(void) const noexcept {
    return this->author;
}

std::string Book::getTitle(void) const noexcept {
    return this->title;
}

unsigned short Book::getYear(void) const noexcept {
    return this->year;
}

std::string Book::getCategory(void) const noexcept {
    return this->category;
}

std::string Book::getGenre(void) const noexcept {
    return this->genre;
}

void Book::setAuthor(const std::string& author) noexcept {
    this->author = author;
}

void Book::setTitle(const std::string& title) noexcept {
    this->title = title;
}

void Book::setYear(const unsigned short year) noexcept {
    this->year = year;
}

void Book::setCategory(const std::string& category) noexcept {
    this->category = category;
}

void Book::setGenre(const std::string& genre) noexcept {
    this->genre = genre;
}