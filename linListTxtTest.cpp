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
#include <fstream>
#include <queue>
using namespace std;

class Node {
public:
    int accountNum;
    string name;
    float balance;
    Node* next;
    Node() {
        accountNum = 0;
        name = "";
        balance = 0.0;
        next = nullptr;
    }
    explicit Node(int accountNum, string name, float balance) {
        this->accountNum = accountNum;
        this->name = std::move(name);
        this->balance = balance;
        this->next = nullptr;
    }
};

class linkedList {
    Node *head;
    Node *tail;
public:
    [[nodiscard]] Node *getHead() const {
        return head;
    }
    [[nodiscard]] Node *getTail() const {
        return tail;
    }
    linkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void addClient(int num, string name, float balance) {
        Node *newNode = new Node(num, std::move(name), balance);
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
    Node *deleteDuplicates(){
        Node *current = head;
        while (current != nullptr){
            Node *prev = current;
            Node *nextNode = current->next;
            while (nextNode != nullptr){
                if (current->accountNum == nextNode->accountNum){
                    prev->next = nextNode->next;
                    delete nextNode;
                    nextNode = prev->next;
                }
                else {
                    prev = nextNode;
                    nextNode = prev->next;
                }
            }
            current = current->next;
        }
        return current;
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
void addClientToFile(const string& filename, int accountNum, const string& name, float balance){
    ofstream outputFile(filename, ios::app);
    if (!outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    outputFile << "\n" << accountNum << ", " << name << ", " << balance;
    outputFile.close();
    cout << "Client added successfully" << endl;
}
//ignore this function if it confuses you
void reverse(){
    linkedList clients;
    ifstream inputFile("filename.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line); //parse the line
        string accountStr, name, balanceStr;
        //slit the line by commas
        if (getline(ss, accountStr, ',') && getline(ss, name, ',') && getline(ss, balanceStr, ',')) {
            //convert account number to int
            //convert balance to float
            //trim leading spaces
            int accountNum = stoi(accountStr);
            float balance = stof(balanceStr);
            name.erase(0, name.find_first_not_of(" "));
            clients.addClient(accountNum, name, balance);
        }
    }
    inputFile.close();
    clients.deleteDuplicates();
    ofstream outputFile("filename.txt", ios::trunc);
    Node *current = clients.getHead();
    while (current != nullptr) {
        outputFile << current->accountNum << ", " << current->name << ", " << current->balance << "\n";
        current = current->next;
    }
    outputFile.close();
    clients.deleteList();
}
void printClients(){
    linkedList clients;
    ifstream inputFile("filename.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line); //parse the line
        string accountStr, name, balanceStr;
        //slit the line by commas
        if (getline(ss, accountStr, ',') && getline(ss, name, ',') && getline(ss, balanceStr, ',')) {
            //convert account number to int
            //convert balance to float
            //trim leading spaces
            int accountNum = stoi(accountStr);
            float balance = stof(balanceStr);
            name.erase(0, name.find_first_not_of(" "));
            clients.addClient(accountNum, name, balance);
        }
    }
    inputFile.close();
    clients.deleteDuplicates();
    ofstream outputFile("filename.txt", ios::trunc);
    Node *current = clients.getHead();
    while (current != nullptr) {
        outputFile << current->accountNum << ", " << current->name << ", " << current->balance << "\n";
        current = current->next;
    }
    outputFile.close();
    cout << "Client List Loaded from File:\n";
    clients.printList(); reverse();
    clients.deleteList();
}
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
}
int main() {
    printClients();
    deleteClient(5313);

    return 0;
}
