//each node has three inputs
class Node {
public:
    int data;
    string name;
    float balance;
    Node* left;
    Node* right;
    explicit Node(int data, string name, float balance){
        this->data = data;
        this->name = std::move(name);
        this->balance = balance;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BinaryTree {
public:
    Node* rootNode;
    explicit BinaryTree(int data, string name, float balance){
        rootNode = new Node(data, std::move(name), balance);
    }
    static Node* insertNode(Node* root, int data, string &name, float balance){
        Node* newNode = new Node(data, name, balance);
        if (root == nullptr){
            root = newNode;
            return root;
        }
        if (data < root->data){
            root->left = insertNode(root->left, data, name, balance);
        }
        else if (data > root->data){
            root->right = insertNode(root->right, data, name, balance);
        }
        return root;
    }
    void insert(int data, string name, float balance){
        rootNode = insertNode(rootNode, data, name, balance);
    }
    void inOrder(Node* current){
        if (current == nullptr){
            return;
        }
        inOrder(current->left);
        cout << current->data << " "
             << current->name << " "
             << current->balance << endl;
             inOrder(current->right);
    }
    void postOrder(Node *current){
        if (current == nullptr){
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " "
             << current->name << " "
             << current->balance << endl;
    }
    void preOrder(Node *current){
        if (current == nullptr){
            return;
        }
        cout << current->data << " "
             << current->name << " "
             << current->balance << endl;
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
            cout << current->data << " "
                 << current->name << " "
                 << current->balance << endl;
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
};
//placehodler hash function - 'most' cases will be unique
int generateID(const string &name) {
    const int prime = 31;
    int hash = 0;
    for (char c : name) {
        hash = hash * prime + c;
        hash %= 100000;
    }
    return hash;
}
int main(){
    //BinaryTree binaryTree(50);
    //binaryTree.insert(30);
    //binaryTree.insert(20);
    //binaryTree.insert(40);
    //binaryTree.insert(70);
    //binaryTree.insert(60);
    //binaryTree.insert(80);
    //cout << "In Order: " << endl;
    //binaryTree.inOrder(binaryTree.rootNode);
    //cout << "\nPost Order: " << endl;
    //binaryTree.postOrder(binaryTree.rootNode);
    //cout << "\nPre Order: " << endl;
    //binaryTree.preOrder(binaryTree.rootNode);
    //BinaryTree::breadthFirst(binaryTree.rootNode);
    //binaryTree.deleteNode(binaryTree.rootNode, 70);
    //cout << "\n";
    //BinaryTree::breadthFirst(binaryTree.rootNode);
    BinaryTree binaryTree(generateID("name1"), "name1", 78.34);
    binaryTree.insert(generateID("name2"), "name2", 28.23);
    binaryTree.insert(generateID("name3"), "name3", 90.23);
    binaryTree.inOrder(binaryTree.rootNode);
    //BinaryTree::breadthFirst(binaryTree.rootNode);

    return 0;
}
