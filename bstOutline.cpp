class Node {
public:
    int data;
    Node* left;
    Node* right;
    explicit Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
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
};

int main(){
    BinaryTree binaryTree(30);
    binaryTree.insert(10);
    binaryTree.insert(5);
    binaryTree.insert(17);
    binaryTree.insert(55);
    //cout << "In Order: " << endl;
    //binaryTree.inOrder(binaryTree.rootNode);
    //cout << "\nPost Order: " << endl;
    //binaryTree.postOrder(binaryTree.rootNode);
    //cout << "\nPre Order: " << endl;
    //binaryTree.preOrder(binaryTree.rootNode);
    BinaryTree::breadthFirst(binaryTree.rootNode);
    binaryTree.deleteNode(binaryTree.rootNode, 55);
    cout << "\n";
    BinaryTree::breadthFirst(binaryTree.rootNode);

    return 0;
}
