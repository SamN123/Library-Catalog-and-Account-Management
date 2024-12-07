#include <iostream>
#include "Node.cpp"

class BinaryTree {
public:
    Node* rootNode;
    explicit BinaryTree(Node* head){
        rootNode = sortedBST(head);
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
    /*static Node* findMiddle(Node* head){
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
    }*/

    static Node* findMiddle(Node *&head){
        Node *fast = head;
        Node *slow = head;
        Node *prev = nullptr;

        while (fast->next != nullptr && fast->next->next != nullptr && !fast->flag && !fast->next->flag){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        /*if (prev != nullptr){
            prev->next = nullptr;
        }*/

        if (prev != nullptr) prev->flag=true;
        return slow;
    }
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
int getLength(Node *head){
    int length = 0;
    while (head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}
