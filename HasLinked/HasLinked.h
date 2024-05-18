#ifndef HASLINKED_H
#define HASLINKED_H

struct Node {
    int key;
    int value;
    Node* next;
    
    Node(int key, int value){
     this->key=key;
     this->value= value;
     this->next=nullptr;
     } 
};

class HashLinked {
private:

    int capacity;
    Node** table; // Array of pointers to Nodes
     int hashFunction(int key);

public:
    
    HashLinked(int size);
    ~HashLinked();
    void insert(int key, int value);
    int search(int key);
    void remove(int key);

    // Linear probing
    int linearProbing(int index, int i);
    // Quadratic probing
    int quadraticProbing(int index, int i);
    // Double hashing
    int doubleHashing(int key, int i);
};
#endif
