#include <iostream>

using namespace std;

bool armstrongNumber(int n) {
    int originalNo = n;
    int temp = n;
    int count = 0;
    while(temp!=0) {
        temp/=10;
        count++;
    }
    int sumOfPower = 0;
    while(n!=0) {
        int digit = n%10;
        sumOfPower +=pow(digit,count);
        n/=10;
    }
    if(sumOfPower == originalNo) return true;
    else return false;

}

int main() {
    int n = 1583;
    if(armstrongNumber(n)) {
        cout<<"Yes the number given is an ArmStrong Number";
    }
    else {
        cout<<"The number is not an ArmStrong Number";
    }
    return 0;


}