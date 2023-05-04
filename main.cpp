#include <iostream>

#include "list.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    List<int> mylist;
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(4);
    mylist.push_front(1);
    mylist.push_front(0);
    
    for(auto it = mylist.begin(); it != mylist.end(); ++it){
        cout << (*it)->value() << endl;
    }
    
    return 0;
}
