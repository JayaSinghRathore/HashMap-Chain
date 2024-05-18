#include <iostream>
#include "Binary.h"
using namespace std;

int main() {
    // Create a binary search tree
    Binary tree;

    // Insert some values into the tree
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);

    // Perform preorder traversal and print the elements
    cout << "Preorder traversal: ";
    tree.PreTraverse(tree.root);
    cout<<endl;
    cout << "Postorder traversal: ";
    tree.PostTraverse(tree.root);
    cout<<endl;
    cout << "Inorder traversal: ";
    tree.InorderTraverse(tree.root);
    cout<<endl;
    cout<< "Search order ";

    tree.Search(8);
    tree.Deletion(4);
    cout<<"after deletion"<<endl;
    tree.InorderTraverse(tree.root);
    cout<<endl;
    return 0;
}
