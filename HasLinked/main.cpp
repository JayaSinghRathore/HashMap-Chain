#include "HasLinked.h"
#include <iostream>
using namespace std;

int main() {
    HashLinked table(10);

    table.insert(100, 10);
    table.insert(200, 20);
    table.insert(1500, 30);
    table.insert(300, 40);

    cout << "Searching for key 100: " << table.search(100) << endl;
    cout << "Searching for key 1500: " << table.search(1500) << endl;

    table.remove(100);
    cout << "After deleting key 100, searching for key 100: " << table.search(100) << endl;

    return 0;
}
