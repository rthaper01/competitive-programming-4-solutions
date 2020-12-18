#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

bool is_sorted(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

void print_vec(vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "\n";
}

void print_bubble_sort(vector<int>& vec) {
    while (!is_sorted(vec)) {
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i + 1]) {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
                print_vec(vec);
            }
        }
    }
}

int main() {
    vector<int> sticks(5);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &sticks[i]);
    }
    print_bubble_sort(sticks);
    return 0;
}