#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.cpp"

using namespace std;

class LinkedList {
    Node *headNode;
public:
    LinkedList(){
        this->headNode = nullptr;
    }

    ~LinkedList(){
        deleteList();
        
    }

    void addNode(std::string title, int date) {
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
        //if (first->title.compare(second->title) < 0) {
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
            std::cout << hex << curr->key;
            cout << " " << curr->title << " " << dec << curr->date << std::endl;
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void deleteList(){
        Node *curr = headNode;
        while (curr != nullptr){
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        headNode = nullptr;
    }
    void sortList(){
        headNode = MergeSort(headNode);
    }
    Node *&getHead() {
        return headNode;
    }
};

#endif
