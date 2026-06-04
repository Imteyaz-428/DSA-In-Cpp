#include <iostream>
#include <vector>
using namespace std;
vector<int> product_ofarray(vector<int> vec) {
    int n = vec.size();

    vector<int> ans(n,1) ;
   
    for(int i = 1; i<n; i++) {
        ans[i] = ans[i-1] * vec[i-1];
    }
    int suffix = 1;
    for(int i =n-1; i>=0 ; i--) {
        ans[i] *= suffix;
        suffix *= vec[i];
    }
    return ans;
    
    

}

int main() {
    vector<int>vec = {1,2,3,4,5};
    auto val = product_ofarray(vec);
    for(int i : val) {
        cout << i << endl;

    }
    return 0;

}