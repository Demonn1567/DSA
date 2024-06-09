#include <iostream>

using namespace std;

int main() {
    int coins[] = {1,3,5,9};
    int amount = 10;

    int DP[4][11];

    for(int row = 0;row<4;row++) {
            int coin = coins[row];
        for(int col = 0;col<11;col++) {
            if(col==0) {
                DP[row][col] =1;
            }
            else if(coin > col) {
                DP[row][col]  = (row > 0 ) ? DP[row-1][col] : 0;
            }

            else {
                DP[row][col]  = DP[row][col-coin];
                DP[row][col] += (row>0) ? DP[row-1][col] : 0;
            }
        }
    }

    for(int row = 0;row<4;row++) {
        for(int col = 0;col<11;col++) {
            cout<<DP[row][col]<<" ";
        }
        cout<<endl;
    }


}