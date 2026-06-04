#include <iostream>
#include <vector>
using namespace std;

void subarray(vector<int>vec, int size) {
    for(int st =0; st<size; st++) {
        for(int end =st; end<size; end++) {
            for(int i=st; i<end; i++) {
                cout << vec[i] ;
            }
            cout << " ";
            
        }
        cout << endl;
    }
}

int main() {
    vector<int>vec = {1,2,3,4,5};
    int size = vec.size();
    subarray(vec, size);
    return 0;

}