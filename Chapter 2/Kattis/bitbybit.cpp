#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    vector<string> bits(32, "?");
    while (scanf("%d", &N) && N != 0) {
        while (N--) {
            string instr;
            int bit1, bit2;
            cin >> instr;
            if (instr == "SET") {
                cin >> bit1;
                bits[bit1] = "1";
            }
            else if (instr == "CLEAR") {
                cin >> bit1;
                bits[bit1] = "0";
            }
            else if (instr == "AND") {
                cin >> bit1 >> bit2;
                if (bits[bit1] == "0" || bits[bit2] == "0") {
                    bits[bit1] = "0";
                }
                else if (bits[bit1] == "1" && bits[bit2] == "1") {
                    bits[bit1] = "1";
                }
                else {
                    bits[bit1] = "?";
                }
            }
            else if (instr == "OR") {
                cin >> bit1 >> bit2;
                if (bits[bit1] == "1" || bits[bit2] == "1") {
                    bits[bit1] = "1";
                }
                else if (bits[bit1] == "0" && bits[bit2] == "0") {
                    bits[bit1] = "0";
                }
                else {
                    bits[bit1] = "?";
                }
            }
        }
        for (int i = 31; i >= 0; i--) {
            cout << bits[i];
            bits[i] = "?";
        }
        cout << endl;
    }
    return 0;
}