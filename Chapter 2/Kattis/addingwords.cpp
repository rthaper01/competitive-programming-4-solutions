#include <iostream>
#include <unordered_map>
#include "stdio.h"
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string add_words(vector<string>& words, unordered_map<string, int>& vars, vector<string>& vals) {
    int result = 0;
    int op = 1;
    for (int i = 1; i < words.size() - 1; i++) {
        if (vars.find(words[i]) != vars.end()) {
            result += op * vars[words[i]];
        }
        else if (words[i] == "+") {
            op = 1;
        }
        else if (words[i] == "-") {
            op = -1;
        }
        else {
            return "unknown";
        }
    }
    if (result < -1000 || result > 1000 || vals[result + 1000].empty()) {
        return "unknown";
    }
    else {
        return vals[result + 1000];
    }
}

void parse(string s, unordered_map<string, int>& vars, vector<string>& vals) {
    if (s == "clear") {
        vars.clear();
        vals.clear();
        vals.resize(2001);
    }
    else {
        stringstream ss {s};
        vector<string> words;
        string token;
        while (getline(ss, token, ' ')) {
            words.push_back(token);
        }
        if (words[0] == "def") {
            ss.clear();
            int value;
            ss.str(words.back());
            ss >> value;
            if (vars.find(words[1]) != vars.end()) {
                vals[vars[words[1]] + 1000].clear();
            }
            vars[words[1]] = value;
            vals[value + 1000] = words[1];
        }
        else if (words[0] == "calc") {
            for (int i = 1; i < words.size(); i++) {
                cout << words[i] << " ";
            }
            cout << add_words(words, vars, vals) << endl;
        }
    }
}

int main() {
    unordered_map<string, int> variables;
    vector<string> values(2001);
    string s;
    while (!getline(cin, s).eof()) {
        parse(s, variables, values);
    }
    return 0;
}