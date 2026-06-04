#include <iostream>
#include <vector>
using namespace std;

int maxsum(vector<int>vec, int size) {
    
    int maxsum = INT_MIN;
    for(int st =0; st<size; st++) {
        int sum =0;
        for(int end = st; end<size; end++) {
            sum = sum+vec[end];
            maxsum = max(sum, maxsum);
        }
    }
    return maxsum;

}

int main() {
    vector<int>vec = {1,2,3,4,5};
    int size = vec.size() ;
    cout << "maxsum :" <<  maxsum(vec, size) << endl;

}