#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "stdio.h"

using namespace std;

int main()
{
    int n, t = 1;
    vector<int> nums;
    while (scanf("%d", &n) == 1)
    {
        nums.resize(n);
        int m, x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            nums[i] = x;
        }

        sort(nums.begin(), nums.end());

        int closest;
        int min_dist = INT_MAX;

        scanf("%d", &m);
        printf("Case %d:\n", t);
        for (int i = 0; i < m; i++)
        {
            int q;
            scanf("%d", &q);
            int j = 0, k = n - 1;
            while (j < k) {
                int dist = abs(nums[j] + nums[k] - q);
                if (dist < min_dist) {
                    closest = nums[j] + nums[k];
                    min_dist = dist;
                }
                if (nums[j] + nums[k] > q) {
                    --k;
                }
                else if (nums[j] + nums[k] < q) {
                    ++j;
                }
                else {
                    break;
                }
            }
            printf("Closest sum to %d is %d.\n", q, closest);
            min_dist = INT_MAX;
        }
        ++t;
    }
    return 0;
}