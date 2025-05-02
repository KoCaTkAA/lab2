#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList<int> list;
    list.Append(10).Append(20);
    list.Prepend(0).Prepend(-10);
    list.InsertAt(15, 3).InsertAt(5, 2);
    cout << "First: " << list.GetFirst() << endl;
    //cout << "Last: " << list.GetLast() << endl;
    cout << "Length: " << list.GetLength() << endl;
    int l = list.GetLength();
    cout << l;
    for (int i = 0; i < l; i++){
        cout << list.Get(i) << " ";
    }
    return 0;
}