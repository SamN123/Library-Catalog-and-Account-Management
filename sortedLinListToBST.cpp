class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int data) {
        this->data = data;
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
    void addNode(int data) {
        Node *newNode = new Node(data);
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
        if (first->data < second->data) {
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
            cout << curr->data << " ";
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
    explicit BinaryTree(int data){
        rootNode = new Node(data);
    }
    static Node* insertNode(Node* root, int data){
        Node* newNode = new Node(data);
        if (root == nullptr){
            root = newNode;
            return root;
        }
        if (data < root->data){
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data){
            root->right = insertNode(root->right, data);
        }
        return root;
    }
    void insert(int data){
        rootNode = insertNode(rootNode, data);
    }
    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " ";
    }
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        cout << current->data << " ";
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
            cout << current->data << " ";
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
    Node *deleteNode(Node *root, int data){
        if (root == nullptr) return nullptr;
        if (data < root->data){
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data){
            root->right = deleteNode(root->right, data);
        }
        else {
            if (root->right == nullptr) return root->left;
            else if (root->left == nullptr) return root->right;
            else {
                Node *temp = successor(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
    static Node *findMiddle(Node *&head){
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
        Node* root = new Node(head->data);
        root->left = left;
        head = head->next;
        root->right = sortedBST(head, mid + 1, end);

        return root;
    }
    void printPostOrder(){
        postOrder(rootNode);
        cout << endl;
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
int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(6);
    list.addNode(3);
    list.addNode(5);
    list.addNode(4);
    list.addNode(7);

    list.printList();
    list.sortList();
    list.printList();

    int length = getLength(list.getHead());

    BinaryTree tree(0);
    tree.rootNode = BinaryTree::sortedBST(list.getHead(), 0, length - 1);
    tree.printPostOrder();

    list.deleteList();

    return 0;
}
