#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec ;
    vec.emplace_back(2);
    vec.emplace_back(4);
    vec.push_back(5);
    
    vec.insert(vec.begin(),4);
    
    for(int i: vec){
        cout << i << endl;
    }
    vec.pop_back();
    cout << "size :" <<  vec.size() << endl;
    cout << "capacity " << vec.capacity() << endl;
    vector<int> arr(3,10);
    for(int i : arr) {
        cout << i << endl;
    }
}