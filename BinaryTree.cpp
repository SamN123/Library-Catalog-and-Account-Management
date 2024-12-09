#include <iostream>
#include "Node.cpp"

using namespace std;

class BinaryTree {
public:
    Node* rootNode;
    explicit BinaryTree(Node* head, int counter){
        rootNode = sortedBST(head, counter);
    }

    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        std::cout << current->key << " ";
        inOrder(current->right);
    }
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        std::cout << current->key << " ";
    }
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        std::cout << current->key << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    static Node* findMiddle(int length, Node* list) {
        length = (length / 2) + 1; 
        //5/2.5 = 2 AND 6/2 = 3  
        //1 2 3 4 5    1 2 3 4 5 6
        //(n-1)/2       n/2     (n/2)-1             

        Node* tempPTR = list;
        for(int i = 1; i < length; i++) {
            tempPTR=tempPTR->next;
        }
        return tempPTR;
        }
    static Node* sortedBST(Node *&head, int length) {
        if (head == nullptr){
            return nullptr;
        }
        //finding the middle value to make root node
        Node *mid = findMiddle(length, head);

        if (mid == nullptr){
            return nullptr;
        }

        Node *root = mid;
        //need to return the root so the tree is split
        if (head == mid){
            return root;
        }
        //we want the head of the left sublist
        //we want the head of the right sublist
        if(length%2==0) {
            root->left = sortedBST(head, (length / 2));
            root->right = sortedBST(mid->next, (length/2)-1);
        }
        else{
            root->left = sortedBST(head, (length-1)/2);
            root->right = sortedBST(mid->next, (length-1)/2);
        } 
        
        return root;
    }

    void printPostOrder(){
        postOrder(rootNode);
        std::cout << std::endl;
    }
    Node* searchNode(Node* rootNode, unsigned long int key2){
        if (rootNode == nullptr || rootNode->key == key2){
            return rootNode;
        }
        if (rootNode->key < key2){
            return searchNode(rootNode->right, key2);
        }
        return searchNode(rootNode->left, key2);
    }
};
