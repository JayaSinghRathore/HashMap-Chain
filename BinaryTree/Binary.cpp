#include "Binary.h"
#include <iostream>
using namespace std;

Node::Node(int value)
{
    data = value;
    this->left = nullptr;
    this->right = nullptr;
}

Binary::Binary()
{
    root = nullptr;
}

//Inserting operations.
void Binary::Insert(int value)
{
    Node *newNode = new Node(value);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    while (current != nullptr)
    {
        if (value > current->data)
        {
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
        else if (value < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else
        {

            return;
        }
    }
}

void Binary::PreTraverse(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << "   ";
    PreTraverse(root->left);
    PreTraverse(root->right);
}

void Binary::PostTraverse(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    PostTraverse(root->left);
    PostTraverse(root->right);
    cout << root->data << "   ";
}

void Binary::InorderTraverse(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    InorderTraverse(root->left);
    cout << root->data << "    ";
    InorderTraverse(root->right);
}

void Binary::Search(int key)
{
    if (root == nullptr)
    {
        cout << "root is empty" << endl;
        return;
    }

    Node *current = root;

    while (current != nullptr)
    {
        if (key == current->data)
        {
            cout << "Key " << key << " found" << endl;
            break;
        }
        else if (key > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
}

void Binary::Deletion(int key) {
    if (root == nullptr) {
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    // Find the node to be deleted and its parent
    while (current != nullptr && current->data != key) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the key is not found
    if (current == nullptr) {
        return;
    }

    // Case 1: Deleting a node with no children
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr) {
            delete root;
            root = nullptr;
        } else if (parent->left == current) {
            delete parent->left;
            parent->left = nullptr;
        } else {
            delete parent->right;
            parent->right = nullptr;
        }
    }
    // Case 2: Deleting a node with one child
    else if (current->left == nullptr || current->right == nullptr) {
        Node* child = (current->left != nullptr) ? current->left : current->right;
        if (parent == nullptr) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    }
    // Case 3: Deleting a node with two children
    else {
        Node* successorParent = current;
        Node* successor = current->right;
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successorParent->left == successor) {
            delete successorParent->left;
            successorParent->left = nullptr;
        } else {
            delete successorParent->right;
            successorParent->right = nullptr;
        }
    }
}
