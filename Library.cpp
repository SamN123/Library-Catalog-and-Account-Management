#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "LinkedList.cpp"

class Library {

// book struct to be used in library class 
// struct Book{
// 	int bookID;
// 	std::string title; 
// 	int dueDate;
//     Book* nextBook;
	
// 	Book(int bookID, std::string title, int dueDate);
// };

// customer struct to be used in library class 
// struct Customer{
// 	std::string firstName;
// 	std::string lastName; 
// 	std::vector<int> borrowedBooks; // list of books the customer currently has 
	
// 	Customer(std::string fName, std::string lName){
// 		firstName = fName;
// 		lastName = lName;
// 	}
// };

	
private:
	// list of books and customers 
    // std::vector<Book> books;     
    // std::vector<Customer> customers; 
    // simulated text files 
    // const std::string catalogFile = "expanded_book_titles.txt";   // for the text file containing all books in library 
    // const std::string clientFile = "expanded_book_titles.txt";  // for the text file containing only borrowed books 

public:

    Library(LinkedList& list1) {
        std::ifstream inputFile("expanded_book_titles.txt");
        if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        }

        std::string line;
        while (getline(inputFile, line)) {
        std::stringstream ss(line); // Load 'line' into the string stream
        std::string title; 
        std::string dateStr;
        int date; 
        
        // Split the line by the pipe delimiter
        if (getline(ss, title, '|') && getline(ss, dateStr, ';')) {
            // Convert the date string to an integer
            date = stoi(dateStr);
        };
        //cout << "Title: " << title << ", Due date: " << date << endl;
        list1.addNode(title, date);
    };
    //list1.printList();
    };
    unsigned long int hashFunction(const std::string& entry) { //generates value based on 
         unsigned long int hash = 0x0;
         
        for(int i = 0; i < 8; i++) {
            hash = i > entry.length()-1 ? hash : hash + entry[i]; //save ascii character value to hash
            hash = i == 7 ? hash : hash << 8; //bit-shift hash left 8 bits to make space for next character
        } 
        
    return hash;
        };

    void saveCatalog() {
        std::ofstream outputFile("expanded_books_titles.txt");
    }

    

	//void saveCatalog(); // save catalog to the file
	//void loadClientList(); // loads book checked out text file 
	//void saveClientList(); // saves checked books into text file 
	void sortList(); // ** function to use sort function (binary search tree?) 
	void searchCatalog();
	void borrowBook(); // adding customer to borrowed books text file 
	void returnBook(); // removing customer from borrowed books text file 
	
};