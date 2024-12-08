#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string title; //holds the title of a book
    int date; //contains the due date of a book, if 0 book is checked in, if >0 book is currently checked out
    unsigned long int key; //generated key from book titles, designed to keep books in alphabetical if sorted by key
    Node *left; //left pointer for binary tree structure
    Node *next; //next pointer for list structure
    Node *right; //right pointer for binary tree structure
    bool flag = false; //flag to assist in forming the BST
    Node(std::string title, int date) { //constructor that loads title and date into the nodes, used to read in from file
        this->title = title;
        this->date = date;
        this->key = 0;
        this->left= nullptr;
        this->right = nullptr;
        this->next = nullptr;
    }
};

#endif
