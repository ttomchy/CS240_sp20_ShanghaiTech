#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int trans[21];

int original(int n) {
    int arr[21];
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (trans[i] != 0) {
            arr[num] = trans[i];
            num++;
        }
    }
    int ans = 0;
    sort(arr, arr + num);
    while(true) {
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num; j++) {
                if (arr[i] + arr[j] == 0 && arr[j] != 0) {
                    arr[i] = 0;
                    arr[j] = 0;
                    ans++;
                }
                else {
                    continue;
                }
            }
        }
        sort(arr, arr + num);
        if (arr[0] == 0 || arr[num - 1] == 0) {
            break;
        }
        else {
            int sta = arr[0];
            int end = arr[num - 1];
            if (sta + end < 0) {
                arr[0] = sta + end;
                arr[num - 1] = 0;
            } 
            else {
                arr[0] = 0;
                arr[num - 1] = sta + end;
            }
            ans++;
        } 
    }
    return ans;
}

int randomalgo(int n) {
    int arr[21];
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (trans[i] != 0) {
            arr[num] = trans[i];
            num++;
        }
    }
    int ans = 0;
    sort(arr, arr + num);
    while(true) {
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num; j++) {
                if (arr[i] + arr[j] == 0 && arr[j] != 0) {
                    arr[i] = 0;
                    arr[j] = 0;
                    ans++;
                }
                else {
                    continue;
                }
            }
        }
        sort(arr, arr + num);
        if (arr[0] == 0 || arr[num - 1] == 0) {
            break;
        }
        else {
            int sta = arr[0];
            int ran = rand() % 3 + 1;
            int end = arr[num - ran];
            if (sta + end < 0) {
                arr[0] = sta + end;
                arr[num - ran] = 0;
            } 
            else {
                arr[0] = 0;
                arr[num - ran] = sta + end;
            }
            ans++;
        } 
    }
    return ans;   
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        trans[i] = 0;
    }
    int i, j, t;
    for (int k = 0; k < m; k++) {
        cin >> i >> j >> t;
        trans[i] -= t;
        trans[j] += t;
    }
    int ans = original(n);
    for (int i = 0; i < 60000; i++) {
        int tmp = randomalgo(n);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}