#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string title;
    int date;
    unsigned long int key;
    Node *left;
    Node *next;
    Node *right;
    bool flag = false;
    Node(std::string title, int date) {
        this->title = title;
        this->date = date;
        this->key = 0;
        this->left= nullptr;
        this->right = nullptr;
        this->next = nullptr;
    }
};

#endif