#include <iostream>
#include "stdio.h"
#include <vector>
#include <sstream>
#include <utility>
#include <set>
#include <map>

using namespace std;

void parse(map<pair<int, int>, string>& patients, map<string, pair<int, int>>& arrivals, int& pos) {
    int command;
    string name;
    cin >> command;
    switch (command) {
        case 0:
        {
            --pos;
            int level;
            cin >> name >> level;
            pair<int, int> info = make_pair(level, pos);
            patients[info] = name;
            arrivals[name] = info;
            break;
        }
        case 1:
        {
            int level;
            cin >> name >> level;
            patients.erase(arrivals[name]);
            arrivals[name].first+= level;
            patients[arrivals[name]] = name;
            break;
        }
        case 2:
        {
            cin >> name;
            patients.erase(arrivals[name]);
            arrivals.erase(name);
            break;
        }
        case 3:
        {
            if (patients.empty()) {
                cout << "The clinic is empty" << endl;
            }
            else {
                auto it = patients.end();
                it--;
                cout << it->second << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    map<pair<int, int>, string> pats;
    map<string, pair<int, int>> reverse;
    int position = 0;
    for (int i = 0; i < N; i++) {
        parse(pats, reverse, position);
    }
    return 0;
}