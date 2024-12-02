#include <iostream>
#include <vector>
#include <string>
#include <fstream>// for file in and out 
using namespace std; 


class Library {

// book struct to be used in library class 
struct Book{
	int bookID;
	string title; 
	string author; 
	bool isOpen; 
	
	Book(int bookID, string title, string author, bool isOpen);
};

// customer struct to be used in library class 
struct Customer{
	int customerID;
	string firstName;
	string lastName; 
	vector<int> borrowedBooks; // list of books the customer currently has 
	
	Customer(int customerID, sting firstName, string lastName); 
};

	
private:
	// list of books and customers 
    vector<Book> books;     
    vector<Customer> customers; 
    // simulated text files 
    const string catalogFile = "catalog.txt";   // for the text file containing all books in library 
    const string borrowedFile = "borrowed.txt";  // for the text file containing only borrowed books 
    
    int hashFunction(const string& title); // prototype for hashing book title to create unique id 
    
public:
	
	void loadCatalog(); // load the book catalog from a text file 
	void saveCatalog(); // save catalog to the file
	void loadCheckedBooks(); // loads book checked out text file 
	void saveCheckedBooks(); // saves checked books into text file 
	void displaySortedCatalog(); // ** function to use sort function (binary search tree?) 
	void searchCatalog();
	void borrowBook(); // adding customer to borrowed books text file 
	void returnBook(); // removing customer from borrowed books text file 
	void viewCustomerBooks();
	
int menu() {
    int choice;
    cout << "\nLibrary Management System\n"
            "1. View All Books\n"
            "2. Search for a Book by Title\n" 
            "3. Borrow a Book\n"
            "4. Return a Book\n"
            "5. View My Borrowed Books\n"
            "6. Exit\n"
            "----------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}


int main() {
	
    Library library;
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1: // View all books in the catalog
                library.displaySortedCatalog(); 
                break;
            case 2: // Search for a book using its title 
                library.searchCatalog(); 
                break;
            case 3: // Borrow a book
                library.borrowBook(); 
                break;
            case 4: // Return a book
                library.returnBook();
                break;
            case 5: // View my borrowed books
                library.viewCustomerBooks(); 
                break;
            case 6: // Exit
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
