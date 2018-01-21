#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node *next = NULL;

    Node(int a) {
        data = a;
    }
};

class Queue {

private:
    Node* front = NULL;
    Node* rear = NULL;

public:
    bool isEmpty();
    void enqueue(Node*);
    Node* dequeue();
    int peek();
};

bool Queue::isEmpty() {
    if (this->front == NULL)
        return true;
    else
        return false;
}

void Queue::enqueue(Node* node) {
    Node* temp;

    if (isEmpty()) {
        front = node;
        rear = node;
    }
    else {
        temp = rear;
        rear = node;
        temp->next = rear;
    }
}

int Queue::peek() {
    return front->data;
}

Node* Queue::dequeue() {
    Node* temp;

    if(!isEmpty()) {
        temp = front;
        front = front->next;
        return temp;
    }
}

class BST {
private:
public:
    void add(int, Node* &);
    Node* root = NULL;
    void visit(Node*);
    void inOrder(Node*);
    void preOrder(Node*);
    void breadthSearch();

    ~BST();
};

BST::~BST() {
    delete root;
}

void BST::add(int a, Node* &root) {
    if (root){
       if (root->data > a) {
            cout << "going left!\n";
            add(a, root->left);
       }
       else {
           cout << "going right!\n";
           add(a, root->right);
       }
    }
    else {
        root = new Node(a);
        cout << "adding node!\n";
    }
}

void BST::inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }

    return;
}

void BST::preOrder(Node* root) {
    if (root != NULL) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void BST::visit(Node* root) {
    cout << "Hello " << root->data << endl;
}

void BST::breadthSearch() {
    Queue que;

    que.enqueue(root);
    while(!que.isEmpty()) {
        Node* r = que.dequeue();
        visit(r);
        if (r->left != NULL) {
            que.enqueue(r->left);
        }
        if (r->right != NULL) {
            que.enqueue(r->right);
        }
    }
}

int main()
{
    BST tree;

    tree.add(5, tree.root);
    tree.add(6, tree.root);
    tree.add(7, tree.root);
    tree.add(8, tree.root);
    tree.add(9, tree.root);
    tree.add(1, tree.root);
    tree.add(2, tree.root);
    tree.add(0, tree.root);

    tree.breadthSearch();

    return 0;
}
