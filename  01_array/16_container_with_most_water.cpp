#include <iostream>
#include <vector>
using namespace std;

int maxwater(vector<int>hight) {
    int st =0; 
    int end = hight.size() -1;
    int maxwater = INT_MIN;
    

    while(st < end) {
        int width = end -st;
        int height = min(hight[st],hight[end]);
        int ans = width*height;
        maxwater = max(maxwater, ans);
        hight[st] <hight[end] ? st++ : end--;

    }
    return maxwater;
}

int main() {
    vector<int> hight = {1,8,6,2,5,4,8,3,7};
    cout << maxwater(hight) << endl;
    return 0;
}