#ifndef BOOK_HXX
#define BOOK_HXX

#include <string>
#include <iostream>

class Book {
private:
    std::string author;
    std::string title;
    unsigned short year;
    std::string category;
    std::string genre;
public:
    Book(void) noexcept;
    Book(const std::string& author, const std::string& title, const unsigned short year, const std::string& category, const std::string& genre) noexcept;
    ~Book(void) noexcept = default;
    Book& operator=(const Book& unit) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Book& unit);
    std::string getAuthor(void) const noexcept;
    std::string getTitle(void) const noexcept;
    unsigned short getYear(void) const noexcept;
    std::string getCategory(void) const noexcept;
    std::string getGenre(void) const noexcept;
    void setAuthor(const std::string& author) noexcept;
    void setTitle(const std::string& title) noexcept;
    void setYear(const unsigned short year) noexcept;
    void setCategory(const std::string& category) noexcept;
    void setGenre(const std::string& genre) noexcept;
};

#endif // BOOK_HXX