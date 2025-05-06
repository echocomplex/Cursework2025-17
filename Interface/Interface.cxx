#include "Interface.hxx"

void Interface::clearInputBuffer(void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::getBook(Book& unit) {
    std::string temp;
    unsigned short temp_year = 0;

    std::cout << "Enter the Author: ";
    std::getline(std::cin, temp);
    unit.setAuthor(temp);
    
    std::cout << "Enter the Book Title: ";
    std::getline(std::cin, temp);
    unit.setTitle(temp);
    
    std::cout << "Enter the Publication Year: ";
    std::cin >> temp_year;
    this->clearInputBuffer();
    unit.setYear(temp_year);
    
    std::cout << "Enter Category (Art/Technical/Reference): ";
    std::getline(std::cin, temp);
    unit.setCategory(temp);
    
    if (temp == "Art") {
        std::cout << "Enter Genre: ";
        std::getline(std::cin, temp);
        unit.setGenre(temp);
    } else {
        unit.setGenre("");
    }
}

int Interface::removeBook(void) {
    int number;
    while (true) {
        std::cout << "Enter Book number to delete (1-" << this->unit.size() << "): ";
        
        if (!(std::cin >> number)) {
            std::cin.clear();
            this->clearInputBuffer();
            std::cerr << "Error: Please enter a number\n\n";
            continue;
        }

        if (number > 0 && number <= this->unit.size()) {
            return number - 1;
        }
        
        std::cerr << "Error: Number must be between 1 and " << this->unit.size() << "\n\n";
    }
}

void Interface::displayMenu(void) {
    std::cout << "\n\n=== Personal Library Database ===" << std::endl;
    std::cout << "1. Display all books" << std::endl;
    std::cout << "2. Add new book" << std::endl;
    std::cout << "3. Remove book" << std::endl;
    std::cout << "4. Find books by author" << std::endl;
    std::cout << "5. Find reference books" << std::endl;
    std::cout << "6. Count books by genre" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    std::cout << "Enter your choice (1-7): ";
}

void Interface::pool(void) {
    short choice = 0;
    Book new_Book;
    List<Book> results;
    std::string search_term;
    
    while (true) {
        this->displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter 1-7: ";
            this->clearInputBuffer();
        }

        this->clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\n[All books in library]\n";
                std::cout << this->unit << std::endl;
                break;
            case 2:
                std::cout << "\n[Adding new book]\n";
                this->getBook(new_Book);
                this->unit.append(new_Book);
                break;
            case 3:
                std::cout << "\n[Removing book]\n";
                this->unit.remove(this->removeBook());
                break;
            case 4:
                std::cout << "Enter author name: ";
                std::getline(std::cin, search_term);
                std::cout << "\n[Books by " << search_term << "]\n";
                this->unit.getBooksByAuthor(results, search_term);
                for (int i = 0; i < results.length(); ++i) 
                    std::cout << results[i] << std::endl;
                results.clear();
                break;
            case 5:
                std::cout << "\n[Reference books]\n";
                this->unit.getReferenceBooks(results);
                for (int i = 0; i < results.length(); ++i) 
                    std::cout << results[i] << std::endl;
                results.clear();
                break;
            case 6:
                std::cout << "Enter genre to count: ";
                std::getline(std::cin, search_term);
                std::cout << "Found " << this->unit.countBooksByGenre(search_term) 
                          << " books in genre '" << search_term << "'" << std::endl;
                break;
            case 7:
                std::cout << "\nExiting program...\n";
                return;
        }

        std::cout << "\nOperation completed. Press Enter to continue...";
        this->clearInputBuffer();
    }
}