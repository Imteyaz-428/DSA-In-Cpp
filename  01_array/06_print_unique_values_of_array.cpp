#include <iostream>
#include <vector>
using namespace std;

void unique_no(vector<int>vec, int size) {
    int ans =0; 
    for(int i=0; i<size; i++)  {
        ans = ans^vec[i];
    }
    cout << "unique no is :" << ans << endl;
}

int main() {
    vector<int> vec = {1,2,4,1,2,34,45,4,34};
    int size = vec.size();
    unique_no(vec, size);
}