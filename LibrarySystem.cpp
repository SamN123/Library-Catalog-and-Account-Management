#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>// for file in and out
#include <queue> 
using namespace std; 

bool testMODE = true;

class Node {
public:
    string title;
    int date;
    int key;
    Node *left;
    Node *next;
    Node *right;
    Node(string title, int date) {
        this->title = title;
        this->date = date;
        this->key = 0;
        this->left= nullptr;
        this->right = nullptr;
        this->next = nullptr;
    }
};

class LinkedList {
    Node *headNode;
public:
    LinkedList(){
        this->headNode = nullptr;
    }
    void addNode(string title, int date) {
        Node *newNode = new Node(title, date);
        if (headNode == nullptr) {
            headNode = newNode;
            return;
        }
        newNode->next = headNode;
        headNode = newNode;
    }
    Node *split(Node *head) {
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if (fast != nullptr) {
                slow = slow->next;
            }
        }
        Node *temp = slow->next;
        slow->next = nullptr;
        return temp;
    }
    Node *merge(Node *first, Node *second) {
        if (first == nullptr) return second;
        if (second == nullptr) return first;
        if (first->title.compare(second->title) < 0) {
            first->next = merge(first->next, second);
            return first;
        }
        else {
            second->next = merge(first, second->next);
            return second;
        }
    }
    Node *MergeSort(Node *head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        Node *second = split(head);
        head = MergeSort(head);
        second = MergeSort(second);
        return merge(head, second);
    }
    void printList() {
        Node *curr = headNode;
        while (curr != nullptr) {
            cout << curr->title << " " << curr->date << endl;
            curr = curr->next;
        }
        cout << endl;
    }
    void deleteList(){
        Node *curr = headNode;
        while (curr != nullptr){
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
    void sortList(){
        headNode = MergeSort(headNode);
    }
    Node *&getHead() {
        return headNode;
    }
};

class BinaryTree {
public:
    Node* rootNode;
    explicit BinaryTree(Node* head){
        rootNode = findMiddle(head);
    }


    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        cout << current->key << " ";
        inOrder(current->right);
    }
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        cout << current->key << " ";
    }
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        cout << current->key << " ";
        preOrder(current->left);
        preOrder(current->right);
    }
    static Node* findMiddle(Node* head){
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            if (fast != nullptr){
                slow = slow->next;
            }
        }
        Node *temp = slow->next;
        slow->next = nullptr;
        return temp;
    }
    static Node* sortedBST(Node *&head, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        Node* left = sortedBST(head, start, mid - 1);
        Node* root = new Node(head->key);
        root->left = left;
        head = head->next;
        root->right = sortedBST(head, mid + 1, end);

        return root;
    }
    void printPostOrder(){
        postOrder(rootNode);
        cout << endl;
    }
    Node *searchNode(Node *root, int key2){
        if (root == nullptr || root->key == key2){
            return root;
        }
        if (root->key < key2){
            return searchNode(root->right, key2);
        }
        return searchNode(root->left, key2);
    }
};
int getLength(Node *head){
    int length = 0;
    while (head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}

class Library {

// book struct to be used in library class 
struct Book{
	int bookID;
	string title; 
	int dueDate;
    Book* nextBook;
	
	Book(int bookID, string title, int dueDate);
};

// customer struct to be used in library class 
struct Customer{
	string firstName;
	string lastName; 
	vector<int> borrowedBooks; // list of books the customer currently has 
	
	Customer(string fName, string lName){
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

    Library(LinkedList& list1) {
        ifstream inputFile("catalog.txt");
        if (!inputFile) {
        cerr << "Error opening file!" << endl;
        }

        string line;
        while (getline(inputFile, line)) {
        stringstream ss(line); // Load 'line' into the string stream
        string title; 
        string dateStr;
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
        int hashFunction(const string& entry) { 
            int sum = 0;
            for (char c : entry) {
                sum += static_cast<int>(c);
            }
            return sum;
        }; // prototype for hashing book title to create unique id */
    
	void loadCatalog(); // load the book catalog from a text file 
	void saveCatalog(); // save catalog to the file
	void loadClientList(); // loads book checked out text file 
	void saveClientList(); // saves checked books into text file 
	void sortList(); // ** function to use sort function (binary search tree?) 
	void searchCatalog();
	void borrowBook(); // adding customer to borrowed books text file 
	void returnBook(); // removing customer from borrowed books text file 
	
};

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

int main() {
	LinkedList list1;
    Library library(list1);
    int choice;
    /*list1.printList();
    list1.sortList();
    list1.printList();*/
    Node* traverse = list1.getHead();
    while(traverse != nullptr) {
        traverse->key = library.hashFunction(traverse->title);
    }
    do {
        choice = menu();
        switch (choice) {
            case 1: // View all books in the catalog
                //library.displaySortedCatalog(); 
                break;
            case 2: // Search for a book using its title 
                //library.searchCatalog(); 
                break;
            case 3: // Borrow a book
                //library.borrowBook(); 
                break;
            case 4: // Return a book
                //library.returnBook();
                break;
            case 5: // Exit
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
