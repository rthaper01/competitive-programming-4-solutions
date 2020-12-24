#include <iostream>
#include <stack>
#include "stdio.h"
#include <vector>
#include <string>

using namespace std;

char NOT(char val) {
    if (val == 'T') {
        return 'F';
    }
    else {
        return 'T';
    }
}

char AND(char val1, char val2) {
    if (val1 == 'F' || val2 == 'F') {
        return 'F';
    }
    else {
        return 'T';
    }
}

char OR(char val1, char val2) {
    if (val1 == 'T' || val2 == 'T') {
        return 'T';
    }
    else {
        return 'F';
    }
}

void print_stack(stack<char> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<char> values;
    stack<char> ops;

    char ch;

    while (N) {
        cin >> ch;
        if (ch == 'T' || ch == 'F') {
            values.push_back(ch);
            N--;
        }
    }
    cin.get(ch);
    while (cin.get(ch)) {
        if (ch == '\n') {
            break;
        }
        else if (ch == ' ') {
            continue;
        }
        else if ('A' <= ch && ch <= 'Z') {
            ops.push(values[ch - 'A']);
        }
        else {
            char top = ops.top();
            ops.pop();
            char next;
            if (!ops.empty()) {
                next = ops.top();
            }
            switch (ch) {
                case '*':
                    ops.pop();
                    ops.push(AND(top, next));
                    break;
                case '+':
                    ops.pop();
                    ops.push(OR(top, next));
                    break;
                case '-':
                    ops.push(NOT(top));
                    break;
            }
        }
    }
    cout << ops.top() << endl;
    return 0;
}