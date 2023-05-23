    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    struct Item {
        int weight;
        int value;
        double valuePerUnitWeight;
    };

    int partition(vector<Item>& items, int low, int high) {
        double pivot = items[high].valuePerUnitWeight;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (items[j].valuePerUnitWeight > pivot) {
                i++;
                swap(items[i], items[j]);
            }
        }

        swap(items[i + 1], items[high]);
        return i + 1;
    }

    void quicksort(vector<Item>& items, int low, int high) {
        if (low < high) {
            int pivot = partition(items, low, high);

            quicksort(items, low, pivot - 1);
            quicksort(items, pivot + 1, high);
        }
    }

    double fractionalKnapsack(int capacity, vector<Item>& items) {
        int n = items.size();
        double totalValue = 0.0;

        quicksort(items, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (capacity <= 0)
                break;

            if (items[i].weight <= capacity) {
                totalValue += items[i].value;
                capacity -= items[i].weight;
            } else {
                double fraction = static_cast<double>(capacity) / items[i].weight;
                totalValue += items[i].value * fraction;
                capacity = 0;
            }
        }
        return totalValue;
    }

    int main() {
        int capacity = 50;

        vector<Item> items = {
            {10, 60, 0.0},
            {20, 100, 0.0},
            {30, 120, 0.0}
        };
        for (auto& item : items) {
            item.valuePerUnitWeight = static_cast<double>(item.value) / item.weight;
        }

        double maxValue = fractionalKnapsack(capacity, items);
        cout << endl;
        cout << "Maximum value in the knapsack: " << maxValue << endl;
    }
