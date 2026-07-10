#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    double price;
    bool available;

    void input() {
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        cout << "Enter Price: ";
        cin >> price;

        available = true;
    }

    void display() {
        cout << "\nTitle      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "ISBN       : " << isbn << endl;
        cout << "Price      : " << price << endl;
        cout << "Status     : ";

        if (available)
            cout << "Available";
        else
            cout << "Borrowed";

        cout << endl;
    }
};

class Library {
private:
    Book books[100];
    int totalBooks;

public:
    Library() {
        totalBooks = 0;
    }

    void addBook() {
        if (totalBooks >= 100) {
            cout << "Library is Full!\n";
            return;
        }

        books[totalBooks].input();
        totalBooks++;

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        if (totalBooks == 0) {
            cout << "No Books Found.\n";
            return;
        }

        for (int i = 0; i < totalBooks; i++) {
            cout << "\nBook " << i + 1 << endl;
            books[i].display();
        }
    }

    void borrowBook() {
        string id;
        cin.ignore();
        cout << "Enter ISBN: ";
        getline(cin, id);

        for (int i = 0; i < totalBooks; i++) {
            if (books[i].isbn == id) {

                if (books[i].available) {
                    books[i].available = false;
                    cout << "Book Borrowed Successfully.\n";
                } else {
                    cout << "Book Already Borrowed.\n";
                }
                return;
            }
        }

        cout << "Book Not Found.\n";
    }

    void returnBook() {
        string id;
        cin.ignore();
        cout << "Enter ISBN: ";
        getline(cin, id);

        for (int i = 0; i < totalBooks; i++) {

            if (books[i].isbn == id) {

                if (!books[i].available) {
                    books[i].available = true;
                    cout << "Book Returned Successfully.\n";
                } else {
                    cout << "Book Already Available.\n";
                }
                return;
            }
        }

        cout << "Book Not Found.\n";
    }

    void searchISBN() {
        string id;
        cin.ignore();
        cout << "Enter ISBN: ";
        getline(cin, id);

        for (int i = 0; i < totalBooks; i++) {

            if (books[i].isbn == id) {
                books[i].display();
                return;
            }
        }

        cout << "Book Not Found.\n";
    }

    void searchTitle() {
        string name;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, name);

        for (int i = 0; i < totalBooks; i++) {

            if (books[i].title == name) {
                books[i].display();
                return;
            }
        }

        cout << "Book Not Found.\n";
    }

    void unavailableBooks() {
        bool found = false;

        for (int i = 0; i < totalBooks; i++) {

            if (!books[i].available) {
                books[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "No Borrowed Books.\n";
    }

    void totalValue() {
        double sum = 0;

        for (int i = 0; i < totalBooks; i++) {
            sum += books[i].price;
        }

        cout << "Total Library Value = " << sum << endl;
    }
};

int main() {

    Library lib;

    int choice;

    do {

        cout << "\n========== LIBRARY MANAGEMENT ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search by ISBN\n";
        cout << "6. Search by Title\n";
        cout << "7. Display Unavailable Books\n";
        cout << "8. Total Library Value\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            lib.borrowBook();
            break;

        case 4:
            lib.returnBook();
            break;

        case 5:
            lib.searchISBN();
            break;

        case 6:
            lib.searchTitle();
            break;

        case 7:
            lib.unavailableBooks();
            break;

        case 8:
            lib.totalValue();
            break;

        case 9:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 9);

    return 0;
}
