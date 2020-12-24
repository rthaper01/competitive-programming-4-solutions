#include <iostream>
#include <stack>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        stack<int> dropped_plates;
        stack<int> taken_plates;

        while (N--) {
            string s;
            int num;
            cin >> s >> num;
            if (s == "DROP") {
                for (int i = 1; i <= num; i++) {
                    dropped_plates.push(i);
                }
                cout << "DROP 2 " << num << endl;
            }
            else if (s == "TAKE") {
                if (taken_plates.size() >= num) {
                    cout << "TAKE 1 " << num << endl;
                    for (int i = 0; i < num; i++) {
                        taken_plates.pop();
                    }
                }
                else {
                    int curr_size = taken_plates.size();
                    if (curr_size > 0) {
                        cout << "TAKE 1 " << taken_plates.size() << endl;
                        num -= curr_size;
                        while (!taken_plates.empty()) {
                            taken_plates.pop();
                        }
                    }
                    cout << "MOVE 2->1 " << dropped_plates.size() << endl;
                    while (!dropped_plates.empty()) {
                        taken_plates.push(dropped_plates.top());
                        dropped_plates.pop();
                    }
                    cout << "TAKE 1 " << num << endl;
                    for (int i = 0; i < num; i++) {
                        taken_plates.pop();
                    }
                }  
            }
        }
        cout << endl;
    }
    return 0;
}