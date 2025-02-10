#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class representing a Book
class Book {
protected:
    string title;
    string author;
    bool isAvailable;

public:
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    virtual void display() {
        cout << "Title: " << title << ", Author: " << author << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    virtual void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "You have borrowed: " << title << endl;
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }

    virtual void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "You have returned: " << title << endl;
        } else {
            cout << title << " was not borrowed." << endl;
        }
    }

    bool getAvailability() {
        return isAvailable;
    }
};

// Derived class representing a Special Edition Book
class SpecialEditionBook : public Book {
private:
    int editionNumber;

public:
    SpecialEditionBook(string t, string a, int edition) : Book(t, a), editionNumber(edition) {}

    void display() override {
        cout << "Special Edition - ";
        Book::display();
        cout << "Edition: " << editionNumber << endl;
    }

    void borrowBook() override {
        if (getAvailability()) {
            cout << "Special edition " << title << " is a high-value book and requires approval to borrow." << endl;
            Book::borrowBook();  // Call base class method if approved
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }
};

// Library System class managing books
class LibrarySystem {
private:
    vector<Book*> books;

public:
    void addBook(Book* b) {
        books.push_back(b);
    }

    void displayBooks() {
        cout << "\nAvailable Books in Library:\n";
        for (Book* b : books) {
            b->display();
        }
    }

    void borrowBook(string title) {
        for (Book* b : books) {
            if (b->getAvailability()) {
                if (title == b->getAvailability()) {
                    b->borrowBook();
                    return;
                }
            }
        }
        cout << "Book not found or is unavailable.\n";
    }

    void returnBook(string title) {
        for (Book* b : books) {
            if (b->getAvailability()) {
                b->returnBook();
                return;
            }
        }
        cout << "No such book borrowed.\n";
    }
};

int main() {
    // Create Library System
    LibrarySystem library;

    // Create books
    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald");
    Book* book2 = new SpecialEditionBook("1984", "George Orwell", 1);

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);

    // Display books
    library.displayBooks();

    // Borrow books
    library.borrowBook("The Great Gatsby");
    library.borrowBook("1984");

    // Display after borrowing
    library.displayBooks();

    // Return books
    library.returnBook("The Great Gatsby");
    library.returnBook("1984");

    // Display after returning
    library.displayBooks();

    // Clean up dynamic memory
    delete book1;
    delete book2;

    return 0;
}

