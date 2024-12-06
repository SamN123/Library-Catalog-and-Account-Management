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
#include <algorithm>
#include <cctype>
using namespace std;

class Node {
public:
    int key;
    string title;
    int date;
    Node *left;
    Node *right;
    Node *next;
    bool stop = false;
    Node(int key, string title, int date) {
        this->key = key;
        this->title = std::move(title);
        this->date = date;
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
    void addNode(int key, string title, int date) {
        Node *newNode = new Node(key, std::move(title), date);
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
        if (first->key < second->key) {
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
            cout << curr->key << " "
                 << curr->title << " "
                 << curr->date << " "
                 << endl;
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
    explicit BinaryTree(int key, string title, int date){
        rootNode = new Node(key, std::move(title), date);
    }
    static Node* insertNode(Node* root, int key, string &title, int date){
        Node* newNode = new Node(key, std::move(title), date);
        if (root == nullptr){
            root = newNode;
            return root;
        }
        if (key < root->key){
            root->left = insertNode(root->left, key, title, date);
        }
        else if (key > root->key){
            root->right = insertNode(root->right, key, title, date);
        }
        return root;
    }
    void insert(int key, string title, int date){
        rootNode = insertNode(rootNode, key, title, date);
    }
    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        if (current->date == 0){
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is available" << " "
                 << endl;
        }
        else {
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is not available" << " "
                 << endl;
        }
        inOrder(current->right);
    }
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        if (current->date == 0){
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is available" << " "
                 << endl;
        }
        else {
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is not available" << " "
                 << endl;
        }
    }
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        if (current->date == 0){
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is available" << " "
                 << endl;
        }
        else {
            cout << "Book ID -" << " "
                 <<  current->key << " "
                 << "Book Title:" << " "
                 << current->title << " - "
                 << "Book is not available" << " "
                 << endl;
        }
        preOrder(current->left);
        preOrder(current->right);
    }
    static void breadthFirst(Node *root){
        if (root == nullptr){
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node *current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left != nullptr){
                q.push(current->left);
            }
            if (current->right != nullptr){
                q.push(current->right);
            }
        }
    }
    static Node *successor(Node *node){
        Node *current = node;
        while (current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }
    Node *deleteNode(Node *root, int key){
        if (root == nullptr) return nullptr;
        if (key < root->key){
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key){
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->right == nullptr) return root->left;
            else if (root->left == nullptr) return root->right;
            else {
                Node *temp = successor(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        return root;
    }
    static Node *findMiddle(Node *&head){
        Node *fast = head;
        Node *slow = head;
        Node *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != nullptr){
            prev->next = nullptr;
        }
        return slow;
    }
    static Node* balancedBST(Node *&head) {
        if (head == nullptr){
            return nullptr;
        }
        //finding the middle value to make root node
        Node *mid = findMiddle(head);
        Node *root = mid;
        //need to return the root so the tree is split
        if (head == mid){
            return root;
        }
        //we want the head of the left sublist
        //we want the head of the right sublist
        root->left = balancedBST(head);
        root->right = balancedBST(mid->next);
        mid->next = nullptr;
        return root;
    }
    static void recreateLinkage(Node *root, Node *&prev){
        if (root == nullptr) return;
        recreateLinkage(root->left, prev);
        if (prev != nullptr) prev->next = root; prev = root;
        recreateLinkage(root->right, prev);
    }
    Node *findReplace(Node *root, int key, int newVal){
        if (root == nullptr) return nullptr;
        if (root->key == key){
            root->key = newVal;
        }
        else if (key < root->key){
            root->left = findReplace(root->left, key, newVal);
        }
        else {
            root->right = findReplace(root->right, key, newVal);
        }
        return root;
    }
    Node *searchNode(Node *root, string title){
        if (root == nullptr || root->title == title){
            return root;
        }
        if (root->title < title){
            return searchNode(root->right, title);
        }
        return searchNode(root->left, title);
    }
};
int generateID(const string &name) {
    const int prime = 31;
    int hash = 0;
    for (char c : name) {
        hash = hash * prime + c;
        hash %= 100000;
    }
    return hash;
}
string trim(const string &str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}
void normalize(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}
void printList(){
    LinkedList list;
    BinaryTree tree(0, " ", 0);
    ifstream fileInput("filename.txt");
    if (!fileInput){
        cerr << "was not able to open file";
        return;
    }
    string line;
    while (getline(fileInput, line)){
        stringstream ss(line);
        string title;
        string dateStr;
        int date = 0;
        if (getline(ss, title, '|') && getline(ss, dateStr, ';')){
            date = stoi(dateStr);
            list.addNode(generateID(title), title, date);
        };
    }
    list.sortList();
    tree.rootNode = BinaryTree::balancedBST(list.getHead());
    Node *prev = nullptr;
    BinaryTree::recreateLinkage(tree.rootNode, prev);
    cout << "\nIn Order Traversal of The BST From File" << endl;
    tree.inOrder(tree.rootNode);
    list.deleteList();
}
void searchList(string &bookTitle){
    LinkedList list;
    BinaryTree tree(0, " ", 0);
    ifstream fileInput("filename.txt");
    if (!fileInput){
        cerr << "was not able to open file";
        return;
    }
    string line;
    while (getline(fileInput, line)){
        stringstream ss(line);
        string title;
        string dateStr;
        int date = 0;
        if (getline(ss, title, '|') && getline(ss, dateStr, ';')){
            date = stoi(dateStr);
            title = trim(title);
            normalize(title);
            list.addNode(generateID(title), title, date);
        };
    }
    bookTitle = trim(bookTitle);
    normalize(bookTitle);
    list.sortList();
    tree.rootNode = BinaryTree::balancedBST(list.getHead());
    Node *prev = nullptr;
    BinaryTree::recreateLinkage(tree.rootNode, prev);
    Node *found = tree.searchNode(tree.rootNode, bookTitle);
    if (found != nullptr){
        cout << bookTitle << " was found" << endl;
    }
    else {
        cout << bookTitle << " was not found" << endl;
    }
    list.deleteList();
}
int main() {
    printList();
    string test = "Pride and Prejudice";
    searchList(test);

    return 0;
}
