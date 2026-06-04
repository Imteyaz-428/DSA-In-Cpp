#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> arr, vector<int> ans,  int i) {
    sort(arr.begin(),arr.end());
    if(i == arr.size()) {
        for(int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        return ;
    }

    //inclusion
    ans.push_back(arr[i]);
    subset(arr, ans, i+1);

    // backtracking
    ans.pop_back();

    //conditon for not repeatation 
    int index = i+1;
    while(index < arr.size() && arr[index] == arr[index-1]) {
        index++;
    }

    // exlusion
    subset(arr, ans,  index);
}


int main() {
    vector<int > arr = {1,2,2,2,2,2};
    vector<int>ans;
    subset(arr, ans,  0);
    
}