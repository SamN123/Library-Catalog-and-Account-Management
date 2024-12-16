// Sam's version of LinListTxtTest
/*
this is how the txt file is structured
1234, name1, 299.39
4321, name2, 232.42
5313, name3, 643.34
1289, name4, 893.23
1289, name5, 893.32
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <cassert>
#include <cstring>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

class Node {
public:
// attributes for book node
    int bookID; 
    string bookTitle; 
    int dueDate; // Added due date for books
// attributes for client node 
    string firstName, lastName;

    Node* next;
    Node* right; // Pointer for right child (if needed)
    Node* left;  // Pointer for left child (if needed)

    Node(int id = 0, string first = "", string last = "", string title = "", int due = 0)
    : bookID(id), firstName(first), lastName(last), bookTitle(title), dueDate(due), next(nullptr), right(nullptr), left(nullptr) {
        // constructor needs to initialize values of attributes in node class 
        //depending on which input file is called in printclient()
    }
    
};

class linkedList {
    Node *head;
public:

    [[nodiscard]] Node *getHead() const {
        return head;
    }

    linkedList() {
        head = nullptr;
    }

    void addClient(string first, string last) {
        Node *newNode = new Node(0, std::move(first), std::move(last));
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            cout << "Account Number: " << current->accountNum << " -- Owner: " << current->name
                 << " -- Current Balance: " << current->balance << "\n";
            current = current->next;
        }
    }

   Node *removeClient(int key){
        Node *current = head;
        Node *prev = nullptr;
        if (current != nullptr && current->accountNum == key){
            head = current->next;
            delete current;
            return head;
        }
        while (current != nullptr && current->accountNum != key){
            prev = current;
            current = current->next;
        }
        if (current == nullptr){
            return head;
        }
        assert(prev != nullptr);
        assert(current != nullptr);
        prev->next = current->next;
        delete current;
        return head;
    } 

    void deleteList(){
        Node *current = head;
        while (current != nullptr){
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

void printClients() {
    linkedList clients;
    ifstream inputFile("Client.txt");
    if (!inputFile) {
        cerr << "Error opening Client file!" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstName, lastName, bookTitle;
        if (getline(ss, firstName, '|') && getline(ss, lastName, '|') && getline(ss, bookTitle, ';')) {
            clients.addClient(firstName, lastName); 
        }
    }
    inputFile.close();

    
}

void printCatalog() {
    linkedList catalog;
    ifstream inputFile("catalog.txt");
    if (!inputFile) {
        cerr << "Error opening Catalog file!" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string title;
        int dueDate;
        if (getline(ss, title, '|') && ss >> dueDate) {
            catalog.addBook(title, dueDate); // Add book to the catalog
        }
    }
    inputFile.close();

    // Print catalog
    cout << "Catalog Loaded from File:\n";
    catalog.printList();
    catalog.deleteList();
}


// to write back into the file after
/*void addClientToFile(const string& filename, int accountNum, const string& name, float balance){
    ofstream outputFile(filename, ios::app);
    if (!outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    outputFile << "\n" << accountNum << ", " << name << ", " << balance;
    outputFile.close();
    cout << "Client added successfully" << endl;
} */


/*
void deleteClient(int num){
    linkedList clients;
    ifstream inputFile("filename.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string accountStr, name, balanceStr;
        if (getline(ss, accountStr, ',') && getline(ss, name, ',') && getline(ss, balanceStr, ',')) {
            int accountNum = stoi(accountStr);
            float balance = stof(balanceStr);
            name.erase(0, name.find_first_not_of(" "));
            clients.addClient(accountNum, name, balance);
        }
    }
    inputFile.close();

    clients.removeClient(num);
    ofstream outputFile("filename.txt", ios::trunc);
    if (!outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    Node *current = clients.getHead();
    while (current != nullptr) {
        outputFile << current->accountNum << ", " << current->name << ", " << current->balance << "\n";
        current = current->next;
    }
    outputFile.close();
    cout << "updated client list written to the file" << endl;
    clients.deleteList();
} */

int main() {
    printClients();
    deleteClient(5313);

    return 0;
}
