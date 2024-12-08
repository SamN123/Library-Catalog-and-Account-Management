#include <iomanip>
#include "BinaryTree.cpp"
#include "Date.cpp"
#include "Library.cpp"
#include "LinkedList.cpp"

using namespace std; 

bool testMODE = false;      //test mode flag to let developers operate extra commands for debugging

int menu() {    //menu prompt with options for program user
    int choice = 0;
    cout << "\nLibrary Management System\n"
            "1. View All Books\n"
            "2. Search for a Book by Title\n" 
            "3. Borrow a Book\n"
            "4. Return a Book\n"
            "5. Exit\n"
            "----------------------------------------\n";
    if(testMODE==true) cout <<
            "6. Reload from file\n"
            "7. Print list of books\n"
            "8. Sort the list of books\n";
            
    cout << dec << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    //declare the linked list books will be read into from the catalogue
	LinkedList list1;
    //declare and construct the library object that will prepare the linked list for 
    Library library(list1);
    
    int choice;             //menu choice storage variable
    int checkoutDays;       //checkoutDays storage variable
    int currentDate;        //variable to store the current date
    Node* temp = nullptr;   //temporary node to traverse linked list and BST when needed
    
    //sort list to prepare it for BST construction
    list1.sortList();
    if(testMODE==true)list1.printList(); //list print out to show that the list is properly ordered by key value

    
    BinaryTree tree(list1.getHead(), library.counter);
    if(testMODE==true)tree.inOrder(tree.rootNode);  //tree print out to verify the BST is properly created
    string input;
    unsigned long int hashvalue = 0;

    if(testMODE == true) {      //testing check to find key values dropped from the BST
        temp = list1.getHead();
        int i = 1;
        while(temp != nullptr){
            if(tree.searchNode(tree.rootNode, library.hashFunction(temp->title)) == nullptr) {
                cout << i << " " << temp->title << endl << temp->key << " " << tree.searchNode(tree.rootNode, library.hashFunction(temp->title)) << endl;
            }
            temp = temp->next; i++;
        }
    }

    cout << dec << "Please enter today's date" << endl << "Format: YYYYMMDD" << endl;
    cin >> currentDate;
    Date date(currentDate);
    do {
        date.setDate(currentDate);
        choice = menu();
        switch (choice) {
            case 1: // View all books in the catalog
                temp = list1.getHead();
                cout << "The entire catalog" << setw(library.width) << "Date Format: YYYYMMDD" << endl;
                while(temp != nullptr) {
                    if(temp->date == 0) cout << left << setw(library.width) << temp->title << " Available";
                    else cout << left << setw(library.width) << temp->title << " Due back: " << temp->date;
                    if(testMODE==true)cout << " " << temp->key; //key print out for verification keys are properly assigned
                    cout << endl;
                    temp = temp->next;
                }
                break;
            case 2: // Search for a book using its title 
                cout << "Please enter the title of the book you'd like" << endl;
                cin.ignore();
                getline(cin, input); 
                cout << endl;
                hashvalue = library.hashFunction(input);
                temp = tree.searchNode(tree.rootNode, hashvalue);
                if(temp == nullptr) cout << input << " not found!" << endl; 
                else {
                    if (temp->date!= 0) 
                    cout << "Sorry, that book is currently checked out\n"
                    "It will be back on: " << temp->date <<
                    "\nPlease try back then!" << endl;
                    else cout << temp->title << " is currently available!" << endl;
                }
                break;
            case 3: // Borrow a book
                cout << "Please enter the title of the book you'd like" << endl;
                cin.ignore();
                getline(cin, input); cout << endl;
                temp = tree.searchNode(tree.rootNode, library.hashFunction(input));
                if(temp == nullptr) cout << input << " not found!" << endl; 
                else {
                    if (temp->date != 0) {
                    cout << "Sorry, that book is currently checked out\n"
                    "It will be back on: " << temp->date <<
                    "\nPlease try back then!" << endl;
                    }
                    else {cout << temp->title << " is currently available!" << endl;
                    cout << "You can borrow this for a max of 14 days\n"
                    "How long would you like to borrow this for?" << endl;
                    cin >> checkoutDays;
                    temp->date = date.newDate(checkoutDays);
                    cout << temp->title << " is due on " << temp->date << endl;
                    }
                }
                break;
            case 4: // Return a book
                cout << "Please enter the title of the book you'd like to return" << endl;
                cin.ignore();
                getline(cin, input); cout << endl;
                temp = tree.searchNode(tree.rootNode, library.hashFunction(input));
                if(temp == nullptr) cout << input <<  " not found!" << endl; 
                else {
                    temp->date = 0;
                    cout << "Thank you! Have a good day" << endl;
                }
                break;
            case 5: // Exit
                cout << "Exiting program\n";
                library.saveCatalog(list1.getHead());
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
