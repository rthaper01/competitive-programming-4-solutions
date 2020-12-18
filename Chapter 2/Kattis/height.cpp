#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int insertion_sort(vector<int>& vec) {
    int steps = 0;
    for (int i = 1; i < vec.size(); i++) {
        int temp = vec[i];
        int j = i;
        while (j >= 1 && vec[j - 1] > temp) {
            vec[j] = vec[j - 1];
            j--;
            steps++;
        }
        vec[j] = temp;
    }
    return steps;
}

int main() {
    int P;
    scanf("%d", &P);
    vector<int> heights(20);
    for (int i = 1; i <= P; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < 20; j++) {
            scanf("%d", &heights[j]);
        }
        int total_steps = insertion_sort(heights);
        printf("%d %d\n", i, total_steps);
    }
    return 0;
}