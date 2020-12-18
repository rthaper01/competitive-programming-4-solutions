#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <utility>
#include <algorithm>
#include "stdio.h"

using namespace std;

deque<string> split_string(string str) {
    deque<string> result;
    stringstream ss {str};
    string level;
    while (getline(ss, level, '-')) {
        result.push_back(level);
    }
    return result;
}

int compare_levels(string s1, string s2) {
    vector<string> hierarchy = {"lower", "middle", "upper"};
    int i1 = find(hierarchy.begin(), hierarchy.end(), s1) - hierarchy.begin();
    int i2 = find(hierarchy.begin(), hierarchy.end(), s2) - hierarchy.begin();
    if (i1 == i2) {
        return 0;
    }
    else if (i1 < i2) {
        return -1;
    }
    else {
        return 1;
    }
}

int compare_classes(string class1, string class2) {
    deque<string> split1 = split_string(class1);
    deque<string> split2 = split_string(class2);
    if (split1.size() < split2.size()) {
        while (split1.size() < split2.size()) {
            split1.push_front("middle");
        }
    }
    else if (split2.size() < split1.size()) {
        while (split2.size() < split1.size()) {
            split2.push_front("middle");
        }
    }
    string curr1 = "", curr2 = "";
    while (curr1 == curr2 && !split1.empty() && !split2.empty()) {
        curr1 = split1.back();
        curr2 = split2.back();
        split1.pop_back();
        split2.pop_back();
    }
    return compare_levels(curr1, curr2);
}

pair<string, string> get_info(string person) {
    string name = "", cls = "";
    stringstream ss {person};
    char ch;
    while (ss >> ch && ch != ':') {
        name += ch;
    }
    ss >> cls;
    pair<string, string> result = {name, cls};
    return result;
}

bool compare_people(string person1, string person2) {
    pair<string, string> info1 = get_info(person1);
    pair<string, string> info2 = get_info(person2);
    int class_comp = compare_classes(info1.second, info2.second);
    if (class_comp == 0) {
        return (info1.first > info2.first);
    }
    else {
        if (class_comp == -1) {
            return true;
        }
        else {
            return false;
        }
    }
}

void sort_people(vector<string>& people) {
    sort(people.begin(), people.end(), compare_people);
    for (int i = 0; i < people.size(); i++) {
        stringstream ss {people[i]};
        string trunc = "";
        char ch;
        while (ss >> ch && ch != ':') {
            trunc += ch;
        }
        people[i] = trunc;
    }
}

void print_equals_signs() {
    for (int i = 0; i < 30; i++) {
        printf("=");
    }
    printf("\n");
}

int main() {
    int T, n;
    vector<string> people;
    scanf("%d", &T);
    while (T--) {
        scanf("%d\n", &n);
        people.resize(n);
        string s;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            people[i] = s;
        }
        sort_people(people);
        for (int i = n - 1; i >= 0; i--) {
            cout << people[i] << endl;
        }
        print_equals_signs();
    }
    return 0;
}