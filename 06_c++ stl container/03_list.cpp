#include <iostream>
#include <list>
using namespace std;

int main() {
    list <int> l = {3,5,3,6};
    l.push_back(9);
    l.emplace_back(8);
    l.push_front(1);
    for(int i: l) {
        cout << i << endl;
    }
    return 0;
    cout << "size :" << l.size() << endl;
    
}