#include <iostream>
#include <vector>
using namespace std;
int profit(vector<int> prices) {
    int maxprofit = INT_MIN;
    
    int buyday = prices[0];
    for(int i = 1;  i< prices.size(); i++){
        if(prices[i] > buyday) {
            int sellday = prices[i];
            maxprofit = max(maxprofit,sellday - buyday);
        }
        if(prices[i] < buyday) {
            buyday = prices[i];
        }
    }
    return maxprofit;
}

int main() {
    vector<int> prices ={7,1,5,3,6,4};
    cout << profit(prices) << endl;
}