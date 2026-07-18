#include <iostream>
#include <vector>
using namespace std;
#include <stack>

int main() {
    vector<int> arr = {100,80,60,70,60,75,85};

    vector<int> ans(arr.size(),0);
    stack<int> s;
    for(int i =0; i<arr.size(); i++) {
        while(s.size()>0 && arr[s.top()] <= arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i+1;
        } else{
            ans[i] = i- s.top();
        }
        s.push(i);

    }
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
   
    
}