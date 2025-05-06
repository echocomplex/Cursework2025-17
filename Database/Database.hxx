#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <List.hxx>
#include <Book.hxx>
#include <Filer.hxx>
#include <iostream>
#include <Crypter.hxx>
#include <ctime>

class Database {
protected:
    Filer file;
    std::string filename;
    std::string filename_enc;
    List<Book> data;
    Crypter crypter;
public:
    Database(void);
    Database(const std::string& filename);
    Database(const List<Book>& unit, const std::string& filename);
    Database(const Database& unit);
    ~Database(void);
    Database& operator=(const Database& unit) noexcept;
    Book& operator[](const unsigned int index) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Database& unit);
    const Book& operator[](const unsigned int index) const noexcept;
    void append(const Book& unit) noexcept;
    void remove(const unsigned int index) noexcept;
    unsigned int size() noexcept;
    void getBooksByAuthor(List<Book>& results, const std::string& author) const noexcept;
    void getReferenceBooks(List<Book>& results) const noexcept;
    unsigned short countBooksByGenre(const std::string& genre) const noexcept;
};

#endif // DATABASE_HXX