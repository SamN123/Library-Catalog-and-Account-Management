#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.cpp"

class LinkedList {
    Node *headNode;
public:
    LinkedList(){
        this->headNode = nullptr;
    }
    //function allow for nodes to be added to the front of the list
    void addNode(std::string title, int date) {
        Node *newNode = new Node(title, date);
        if (headNode == nullptr) {
            headNode = newNode;
            return;
        }
        newNode->next = headNode;
        headNode = newNode;
    }
    //split function allows for the the MergeSort function to be recursively split in half
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
    //merges two halves back together in their respected order
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
    //MergeSort function allows for the the recursive call chain of spliting the list
    //into sinlge nodes in order to be compared and sorted
    Node *MergeSort(Node *head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        Node *second = split(head);
        head = MergeSort(head);
        second = MergeSort(second);
        return merge(head, second);
    }
    //traverse the list for the purpose of displaying the list
    void printList() {
        Node *curr = headNode;
        while (curr != nullptr) {
            std::cout << curr->key << " " << curr->title << " " << curr->date << std::endl;
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    //traversing the list and deleting each element from memory
    void deleteList(){
        Node *curr = headNode;
        while (curr != nullptr){
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
    //instead of calling thee MergeSort funciton on the list itself we call
    //this function instead in order to avoid having to pass anythigng in the 
    //parameter when the function is instantiated
    void sortList(){
        headNode = MergeSort(headNode);
    }
    //this function will return the head of the linked list
    Node *&getHead() {
        return headNode;
    }
};

#endif
