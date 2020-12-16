#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

void print_2d_vector(vector<vector<int>>& vec);
void print_vector(vector<int>& vec);

void flip_rows(vector<vector<int>>& kernel) {
    int h = kernel.size();
    for (int i = 0; i < h / 2; i++) {
        vector<int> temp = kernel[i];
        kernel[i] = kernel[h - 1 - i];
        kernel[h - 1 - i] = temp;
    }
}

void flip_columns(vector<vector<int>>& kernel) {
    int h = kernel.size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < kernel[i].size() / 2; j++) {
            int temp = kernel[i][j];
            kernel[i][j] = kernel[i][kernel[i].size() - 1 - j];
            kernel[i][kernel[i].size() - 1 - j] = temp;
        }
    }
}

void convolute(vector<vector<int>>& kernel) {
    flip_rows(kernel);
    flip_columns(kernel);
}

vector<vector<int>> sub_vector(vector<vector<int>>& vec, int i, int j, int k, int l) {
    vector<vector<int>> result(k);
    for (int a = 0; a < k; a++) {
        for (int b = 0; b < l; b++) {
            result[a].push_back(vec[a + i][b + j]);
        }
    }
    return result;
}

int multiply(vector<vector<int>>& vec1, vector<vector<int>>& vec2) {
    int total = 0;
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec1[i].size(); j++) {
            total += vec1[i][j] * vec2[i][j];
        }
    }
    return total;
}

vector<vector<int>> multiply_locally(vector<vector<int>>& vec1, vector<vector<int>>& vec2) {
    int n = vec1.size(), m = vec2.size();
    vector<vector<int>> result(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        for (int j  = 0; j < (int) vec1[0].size() - (int) vec2[0].size() + 1; j++) {
            vector<vector<int>> sub_matrix = sub_vector(vec1, i, j, (int) vec2.size(), (int) vec2[0].size());
            int total = multiply(sub_matrix, vec2);
            result[i].push_back(total);
        }
    }
    return result;
}

void print_2d_vector(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_vector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

int main() {
    int H, W, N, M, entry;
    scanf("%d%d%d%d", &H, &W, &N, &M);
    vector<vector<int>> image(H);
    vector<vector<int>> ker(N);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &entry);
            image[i].push_back(entry);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &entry);
            ker[i].push_back(entry);
        }
    }
    convolute(ker);
    vector<vector<int>> transformed = multiply_locally(image, ker);
    print_2d_vector(transformed);
    return 0;
}