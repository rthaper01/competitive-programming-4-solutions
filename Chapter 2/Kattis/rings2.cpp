#include <iostream>
#include <vector>
#include <cmath>
#include "stdio.h"

using namespace std;

void print_tree(vector<vector<int>>& tree);

bool in_bounds(vector<vector<int>>& vec, int i, int j) {
    if (i >= vec.size() || i < 0 || j >= vec[0].size() || j < 0) {
        return false;
    }
    return true;
}

bool is_filled(vector<vector<int>>& tree) {
    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (tree[i][j] == -1) {
                return false;
            }
        }
    }
    return true;
}

void label_ring(vector<vector<int>>& tree, int n) {
    vector<vector<int>> tree_copy = tree;
    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (tree[i][j] == -1 && ((in_bounds(tree, i - 1, j) && tree[i - 1][j] == n - 1) || (in_bounds(tree, i + 1, j) && tree[i + 1][j] == n - 1) || (in_bounds(tree, i, j - 1) && tree[i][j - 1] == n - 1) || (in_bounds(tree, i, j + 1) && tree[i][j + 1] == n - 1))) {
                tree_copy[i][j] = n;
            }
        }
    }
    tree = tree_copy;
}

int label_rings(vector<vector<int>>& tree) {
    int level = 1;
    while (!is_filled(tree)) {
        label_ring(tree, level);
        level++;
    }
    return level - 1;
}

void print_tree(vector<vector<int>>& tree) {
    int num_rings = label_rings(tree);
    int fillers;
    if (num_rings < 10) {
        fillers = 2;
    }
    else {
        fillers = 3;
    }
    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (tree[i][j] != 0) {
                int n = log10(tree[i][j]) + 1;
                for (int k = 1; k <= fillers - n; k++) {
                    cout << ".";
                }
                cout << tree[i][j];
            }
            else {
                for (int k = 1; k <= fillers; k++) {
                    cout << ".";
                }
            }
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    string line;
    scanf("%d%d", &n, &m);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++) {
        tree[i].resize(m);
        cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == 'T') {
                if (j == 0 || j == m - 1 || i == 0 || i == n -1) {
                    tree[i][j] = 1;
                }
                else {
                    tree[i][j] = -1;
                }
            }
            else {
                tree[i][j] = 0;
            }
        }
    }
    print_tree(tree);
    return 0;
}