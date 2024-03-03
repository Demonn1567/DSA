#include <iostream>

using namespace std;

int main() {
    int coins[] = {1,2,5};
    int sizeOfCoins = sizeof(coins)/sizeof(coins[0]);
    int amount =7;
    int numberOfWays[sizeOfCoins][amount+1];
    for(int ci=0;ci<sizeOfCoins;ci++) {
        int coin = coins[ci];
        for(int am=0;am<amount+1;am++) {
            if(am==0) {
                numberOfWays[ci][am] = 0;
            }
            else if(coin >am && ci>0) {
                numberOfWays[ci][am] = numberOfWays[ci-1][am];
            }
            else if(ci>0) {
            numberOfWays[ci][am]= numberOfWays[ci][am-coin] +numberOfWays[ci-1][am];
            }
            else {
                numberOfWays[ci][am] = numberOfWays[ci][am-coin];
            }
        }
    }
    cout<<"Number of ways to get the amount"<<amount<<" :"<<numberOfWays[sizeOfCoins-1][amount-1];
    return 0;
}