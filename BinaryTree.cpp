#include <iostream>
#include "Node.cpp"

class BinaryTree {
public:
    Node* rootNode;
    // Constructor for the Binary Tree Class with rootNode initialized when the object is constructed
    explicit BinaryTree(Node* head){
        rootNode = sortedBST(head);
    }
    // In Order traversal of the binary tree with sorted output 
    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        std::cout << current->key << " ";
        inOrder(current->right);
    }
    // Post Order traversal of the binary tree with sorted output 
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        std::cout << current->key << " ";
    }
    // Pre Order traversal of the binary tree with sorted output 
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        std::cout << current->key << " ";
        preOrder(current->left);
        preOrder(current->right);
    }
    // Finds and returns the middle node in linked list using fast and slow pointers 
    static Node* findMiddle(Node *&head){
        Node *fast = head;
        Node *slow = head;
        Node *prev = nullptr;

        while (fast->next != nullptr && fast->next->next != nullptr && !fast->flag && !fast->next->flag){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr) prev->flag=true;
        return slow;
    }
    // Recursive conversion of a sorted link list into a Binary Search Tree 
    static Node* sortedBST(Node *&head) {
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
        root->left = sortedBST(head);
        root->right = sortedBST(mid->next);
        return root;
    }
    // Displays the post order format of the Binary Tree  
    void printPostOrder(){
        postOrder(rootNode);
        std::cout << std::endl;
    }
    // Searches for a specific node with a given key using recursion 
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
// Returns the length of the Binary Tree 
int getLength(Node *head){
    int length = 0;
    while (head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}
