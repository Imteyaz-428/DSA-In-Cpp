#include <iostream>
#include <vector>
using namespace std;

int addDigits(int num) {
    if(num < 10) {
        return num;
    }
    int sum = 0;
    while( num >= 0) {
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }
    if(sum > 10) {
        addDigits(sum);
    }
    return sum;
}

int main() {
    int num = 38;
    addDigits(num);
}
