#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int num[n + 1][n + 1];
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            num[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        cin >> num[i][i];
        dp[i][i] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            for (int k = j; k < i + j; k++) {
                if (num[j][k] == 0) {
                    continue;
                }
                else {
                    if(num[j][k] == num[k+1][j + i]) {
                        num[j][i + j] = num[j][k] + 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            dp[j][j + i] =  i + 1;
            for (int k = j; k < i + j; k++) {
                if(num[j][k] == num[k + 1][i + j] && dp[j][k] == 1 && dp[k + 1][j + i] == 1) {
					dp[j][j + i] = 1;
				}
                else {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}