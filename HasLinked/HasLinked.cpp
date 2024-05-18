#include "HasLinked.h"

HashLinked::HashLinked(int size)
{
    this->capacity = size;
    table = new Node *[capacity](); //array of pointers
    for (int i = 0; i < capacity; ++i)
    {
        table[i] = nullptr;
    }
}

HashLinked::~HashLinked()
{
    for (int i = 0; i < capacity; ++i)
    {
        Node *current = table[i];
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

// Hash function
int HashLinked::hashFunction(int key)
{
    return (key % capacity);
}

// Insert a key-value pair into the hash map
void HashLinked::insert(int key, int value)
{
    int index = hashFunction(key);

    Node *newNode = new Node(key, value);
    if (!table[index])
    {
        table[index] = newNode;
    }
    else
    {
        Node *current = table[index];
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Search for a key in the hash map and return its value if found
int HashLinked::search(int key)
{
    int index = hashFunction(key);
    Node *current = table[index];
    while (current)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Remove a key from the hash map
void HashLinked::remove(int key)
{
    int index = hashFunction(key);
    Node *current = table[index];
    Node *prev = nullptr;
    while (current)
    {
        if (current->key == key)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Linear probing
int HashLinked::linearProbing(int index, int i)
{
    return (index + i) % capacity;
}

// Quadratic probing
int HashLinked::quadraticProbing(int index, int i)
{
    return (index + i * i) % capacity;
}

// Double hashing
int HashLinked::doubleHashing(int key, int i)
{
    return (hashFunction(key) + i * (1 + (key % (capacity - 1)))) % capacity;
}
