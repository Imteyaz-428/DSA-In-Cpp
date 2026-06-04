#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {2,1,4,2,5,3};
    vector<int> :: iterator it;
    cout  << *(vec.begin()) << endl;
    // for( it =vec.begin(); it !=vec.end(); it++) {
    //    cout << *(it) << endl;
    

    // }
    return 0;
    for(auto it = vec.rbegin(); it!=vec.rend(); it++) {
        cout << *(it) << endl;
    }
}