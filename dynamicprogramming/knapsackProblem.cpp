#include <iostream>

using namespace std;

int main() {
    int coins[] = {1,2,5};
    int sizeOfCoins = sizeof(coins)/sizeof(coins[0]);
    int amount =7;
    int numberOfWays[sizeOfCoins][amount+1];
    for(int i=0;i<sizeOfCoins;i++) {
        numberOfWays[i][0] = 1;
    }
    for(int ci=0;ci<sizeOfCoins;ci++) {
        int coin = coins[ci];
        for(int am=1;am<amount+1;am++) {
            if(coin > am) {
                numberOfWays[ci][am] = (ci>0) ? numberOfWays[ci-1][am] : 0;
            }
              
            else {
                numberOfWays[ci][am] = numberOfWays[ci][am-coin];
                if(ci>0) {
                    numberOfWays[ci][am] +=numberOfWays[ci-1][am];
                }
            }
        }
    }
    for(int i=0;i<sizeOfCoins;i++) {
        for(int j=0;j<=amount;j++) {
            cout<<numberOfWays[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}