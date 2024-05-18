#ifndef BINARY_H
#define BINARY_H

class Node{
 public:
    int data;
    Node *left;
    Node *right;
    Node(int);

};

class Binary{
  public: 
    Node* root;
    Binary();
    void Insert(int);  
    void PreTraverse(Node*);
    void PostTraverse(Node*);
    void InorderTraverse(Node*);
    void Search(int);
    void Deletion(int);   
};
#endif