#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> arr,vector<int> ans, int index) {
    if( index == arr.size()) {
        for(int i : arr) {
            cout << i << " ";
        }
        cout << endl;
        return ;
    }

    for(int i =index; i<arr.size(); i++) {
        swap(arr[i], arr[index]);
        permutation(arr, ans, index+1);
        
        //backtracking
        swap(arr[i], arr[index]);
    }
}

int main() {
    vector<int> arr = {1,2,3};
    vector<int> ans;
    permutation(arr, ans, 0);
    
}