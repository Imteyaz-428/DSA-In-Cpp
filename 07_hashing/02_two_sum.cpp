#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// time comp:- O(nlogn)
vector<pair<int,int>> two_sum(vector<int>arr, int target) {
    int size=arr.size();
    vector<pair<int,int>>ans;
    sort(arr.begin(), arr.end());
    int st =0;
    int end= size-1;
    while(st < end) {
        if(arr[st]+ arr[end] == target) {
            ans.push_back({arr[st],arr[end]});
            return ans;
        } else if(arr[st] + arr[end] > target) {
            end --;
        } else {
            st++;
        }
    }
    return {{-1,-1}};
}

// time complexity :- O(n)
vector<pair<int,int>> twoSum(vector<int>arr, int target) {
    vector<pair<int,int>> ans;
    unordered_set<int> s;
    for(int i =0; i<arr.size(); i++) {
        int a= arr[i];
        int b= target-arr[i];
        if(s.find(b) != s.end()) {
            ans.push_back({a,b});
            return ans;
        }
        s.insert(a);
    }
    return {{-1,-1}};
}


int main() {
    vector<int> arr= {5,2,11,7,15};
    int target =9;
    auto val= twoSum(arr, target) ;
    for(auto i:val) {
        cout << i.first << "," << i.second << endl;
    }
    auto vals= two_sum(arr, target) ;
    for(auto i:vals) {
        cout << i.first << "," << i.second << endl;
    }
    
    
}
