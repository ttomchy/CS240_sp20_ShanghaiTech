#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cost[51][51][51][51];
char grid[51][51];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> &grid[i][1];
        for (int j = 1; j < n + 1; j++) {
            if (grid[i][j] != '#') {
                cost[i][i][j][j] = 0;
            }
            else {
                cost[i][i][j][j] = 1;
            }           
        } 
    }
    int mincost;
    for (int length = 1; length < n + 1; length++) {
        for (int width = 1; width < n + 1; width++) {
            for (int x1 = 1; x1 < n + 2 - length; x1++) {
                for (int y1 = 1; y1 < n + 2 - width; y1++) {
                    int x2 = x1 + length - 1;
                    int y2 = y1 + width - 1;
                    if (length != 1 || width != 1) {
                        cost[x1][x2][y1][y2] = (x2 - x1 + 1) > (y2 - y1 + 1) ? x2 - x1 + 1 : y2 - y1 + 1;
                    }
                    mincost = cost[x1][x2][y1][y2];
                    for (int tmpx = x1; tmpx < x2; tmpx++) {
                        int tmp = cost[x1][tmpx][y1][y2] + cost[tmpx + 1][x2][y1][y2];
                        tmp < mincost ? mincost = tmp : mincost = mincost; 
                    }
                    for (int tmpy = y1; tmpy < y2; tmpy++) {
                        int tmp = cost[x1][x2][y1][tmpy] + cost[x1][x2][tmpy + 1][y2];
                        tmp < mincost ? mincost = tmp : mincost = mincost;
                    }
                    cost[x1][x2][y1][y2] = mincost;
                }
            }
        }
    }
    cout << cost[1][n][1][n];
    return 0;
}