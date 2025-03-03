#include <iostream>
using namespace std;

void fractionalKnapsack(int n, float profit[], float weight[], float capacity) {
    float ratio[n], totalValue = 0;

    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            totalValue =totalValue+profit[i];
            capacity =capacity-weight[i];
        } else {
            totalValue=totalValue+ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum Profit: " << totalValue << endl;
}

int main() {
    int n;
    float capacity;

    cout << "Enter the number of items: ";
    cin >> n;


    float profit[n], weight[n];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Input: Capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;


    fractionalKnapsack(n, profit, weight, capacity);

    return 0;
}

