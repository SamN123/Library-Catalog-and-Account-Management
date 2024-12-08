//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <fstream>// for file in and out
//#include <queue> 
//#include <bits/stdc++.h>

//#include "Node.cpp"
#include "BinaryTree.cpp"
#include "Date.cpp"
#include "Library.cpp"
#include "LinkedList.cpp"

using namespace std; 

bool testMODE = false;

int menu() {
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
	LinkedList list1;
    Library library(list1);
    
    int choice;
    int checkoutDays;
    int currentDate;
    int counter = 1;

    Node* traverse = list1.getHead();
    while(traverse != nullptr) {
        traverse->key = library.hashFunction(traverse->title);
        //cout << hex << traverse->key << endl;
        traverse = traverse->next;
        counter++;
    }
    
    //list1.printList();
    list1.sortList();
    list1.printList();

    
    BinaryTree tree(list1.getHead(), counter);
    //tree.inOrder(tree.rootNode);    
    string input;
    unsigned long int hashvalue = 0;

    traverse = list1.getHead();
    int i = 1;
    while(traverse != nullptr){
        if(tree.searchNode(tree.rootNode, library.hashFunction(traverse->title)) == nullptr) {
        cout << i << " " << traverse->title << endl << traverse->key << " " << tree.searchNode(tree.rootNode, library.hashFunction(traverse->title)) << endl;
        }
        traverse = traverse->next; i++;
    }

    cout << dec << "Please enter today's date" << endl;
    cin >> currentDate;
    Date date(currentDate);
    do {
        date.setDate(currentDate);
        choice = menu();
        switch (choice) {
            case 1: // View all books in the catalog
                traverse = list1.getHead();
                cout << hex << "The entire catalog" << endl;
                while(traverse != nullptr) {
                    cout << traverse->title << " Due Date: " << traverse->date;
                    cout << " " << traverse->key;
                    cout << endl;
                    traverse = traverse->next;
                }
                break;
            case 2: // Search for a book using its title 
                cout << "Please enter the title of the book you'd like" << endl;
                cin.ignore();
                getline(cin, input); 
                cout << endl;
                hashvalue = library.hashFunction(input);
                traverse = tree.searchNode(tree.rootNode, hashvalue);
                if(traverse == nullptr) cout << "Book not found!" << endl; 
                else {
                    if (traverse->date!= 0) 
                    cout << "Sorry, that book is currently checked out\n"
                    "It will be back on: " << traverse->date <<
                    "\nPlease try back then!" << endl;
                    else cout << traverse->title << " is currently available!" << endl;
                }
                break;
            case 3: // Borrow a book
                cout << "Please enter the title of the book you'd like" << endl;
                cin.ignore();
                getline(cin, input); cout << endl;
                traverse = tree.searchNode(tree.rootNode, library.hashFunction(input));
                if(traverse == nullptr) cout << "Book not found!" << endl; 
                else {
                    if (traverse->date != 0) {
                    cout << "Sorry, that book is currently checked out\n"
                    "It will be back on: " << traverse->date <<
                    "\nPlease try back then!" << endl;
                    }
                    else {cout << traverse->title << " is currently available!" << endl;
                    cout << "You can borrow this for a max of 14 days\n"
                    "How long would you like to borrow this for?" << endl;
                    cin >> checkoutDays;
                    traverse->date = date.newDate(checkoutDays);
                    cout << traverse->title << " is due on " << traverse->date << endl;
                    }
                }
                break;
            case 4: // Return a book
                cout << "Please enter the title of the book you'd like to return" << endl;
                cin.ignore();
                getline(cin, input); cout << endl;
                traverse = tree.searchNode(tree.rootNode, library.hashFunction(input));
                if(traverse == nullptr) cout << "Book not found!" << endl; 
                else {
                    traverse->date = 0;
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
