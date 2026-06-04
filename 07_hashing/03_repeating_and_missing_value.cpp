#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;




int main() {
    vector<int> arr = {9,1,7,8,9,2,3,6,4};
    int size = arr.size();
    int expectedSum = size*(size+1)/2;
    int actualSum =0;
    int a=0;
    unordered_set<int> s;
    for(int i =0; i<size; i++) {
        actualSum += arr[i];
        
        if(s.find(arr[i]) != s.end()) {
            a= arr[i];
        }
        s.insert(arr[i]);
    }
    int b =  expectedSum -(actualSum -a);
    cout << a << "," << b << endl;
    cout << "repeating_value is :" <<  a << endl;
    cout << "missing_value is :" << b << endl;
    

}