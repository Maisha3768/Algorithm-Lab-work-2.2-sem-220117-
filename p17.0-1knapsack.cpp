#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout<<"enter numbers:";
    cin >> n;
    int weight[n], value[n];

    cout<<"enter weight:";

    for (int i = 0; i < n; i++)
        cin >> weight[i];

        cout<<"enter value:";

    for (int i = 0; i < n; i++)
        cin >> value[i];

    int W;
    cout<<"enter capacity:";
    cin >> W;

    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}


