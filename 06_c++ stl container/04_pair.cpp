#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {3,5,2,6};
    vector<pair<int, int >> arr = {{2,4},{6,5},{7,4}};
    arr.emplace_back(4,2);
    arr.push_back({6,1});
    for(auto val : arr){
        cout << val.first << " ," << val.second << endl;
    }
}