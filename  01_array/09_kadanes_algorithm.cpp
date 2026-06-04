#include <iostream>
#include <vector>
using namespace std;

int maxsubbarraysum(vector<int>vec, int size) {
    int currsum = 0;
    int maxsum = INT_MIN;
    for(int i=0; i<size; i++) {
        currsum += vec[i];
        maxsum = max(currsum, maxsum);

        if(currsum < 0) {
            currsum =0;
        }
    }
    return maxsum;
}

int main() {
    vector<int>vec= {1,2,3,-4,5};
    int size = vec.size();
    cout <<"maxsum :" << maxsubbarraysum(vec, size) << endl;
}