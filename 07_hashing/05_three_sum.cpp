#include <iostream>
#include <vector>
#include <set>
using namespace std;


void three_sum(vector<int> arr) {
    vector<vector<int>> ans;
    set<vector<int>>s;
    int size = arr.size();
    int target = 0;
    sort(arr.begin(), arr.end());
    for(int i =0; i<size; i++) {
        int a = arr[i];
        int st =i+1;
        int end= size-1;
        while(st < end) {
            if(a+arr[st] + arr[end]== 0) {
                vector<int> vec = {a, arr[st], arr[end]};
                sort(vec.begin(),vec.end());
                if(s.find(vec) == s.end()){
                    s.insert(vec);
                    ans.push_back(vec);
                }
                st++;
                end--;

               
               
                
            } else if(a+arr[st] + arr[end] > 0) {
                end--;
            } else {
                st++;
            }
        }
    }
    for(auto i : ans) {
        for(int j :i) {
            cout << j << ",";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    vector<int> arr = {-1,0,1,7,-1,-4};
    three_sum(arr);

}