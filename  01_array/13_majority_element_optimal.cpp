#include <iostream>
#include <vector>
using namespace std;

vector<int>majorityElement(vector<int>vec, int size) {
    int freq =0;
    int ans =vec[0];
    vector<int> ansr;
    sort(vec.begin(), vec.end());
    for(int i =1; i<size; i++) {
        if(vec[i] == vec[i-1]) {
            freq++;
        } else{
            freq = 1;
            ans = vec[i];
        }
        if(freq >size/2) {
            ansr.push_back(ans);
            
        }
    }
    return ansr;
}

int main() {
    vector<int> vec = {1,2,3,2,3,2,2,3,2};
    int size = vec.size() ;
    auto val = majorityElement(vec, size);
    cout << val[0] << endl;
}