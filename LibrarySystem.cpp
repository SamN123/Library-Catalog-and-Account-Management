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
	int dueDate;
	
	Book(int bookID, string title, int dueDate);
};

// customer struct to be used in library class 
struct Customer{
	string firstName;
	string lastName; 
	vector<int> borrowedBooks; // list of books the customer currently has 
	
	Customer(sting fName, string lName){
		firstName = fName;
		lastName = lName;
	}
};

	
private:
	// list of books and customers 
    vector<Book> books;     
    vector<Customer> customers; 
    // simulated text files 
    const string catalogFile = "Catalog.txt";   // for the text file containing all books in library 
    const string clientFile = "Client.txt";  // for the text file containing only borrowed books 

public:

        int hashFunction(const string& entry){
        int sum = 0;
        for (char c : entry) {
        sum += static_cast<int>(c);
         }
        return sum;
        }; // prototype for hashing book title to create unique id 
    
	void loadCatalog(); // load the book catalog from a text file 
	void saveCatalog(); // save catalog to the file
	void loadClientList(); // loads book checked out text file 
	void saveClientList(); // saves checked books into text file 
	void sortList(); // ** function to use sort function (binary search tree?) 
	void searchCatalog();
	void borrowBook(); // adding customer to borrowed books text file 
	void returnBook(); // removing customer from borrowed books text file 
	
	
int menu() {
    int choice;
    cout << "\nLibrary Management System\n"
            "1. View All Books\n"
            "2. Search for a Book by Title\n" 
            "3. Borrow a Book\n"
            "4. Return a Book\n"
            "5. Exit\n"
            "----------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

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
            case 5: // Exit
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

