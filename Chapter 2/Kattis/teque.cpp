#include <iostream>
#include <deque>
#include "stdio.h"

using namespace std;

class Teque {
public:
    Teque();
    void push_back(int x);
    void push_front(int x);
    void push_middle(int x);
    int get(int i) const;
    int size() const;

private:
    deque<int> front_half;
    deque<int> back_half;
};

Teque::Teque() {}

int Teque::size() const {
    return front_half.size() + back_half.size();
}

int Teque::get(int i) const {
    if (i < this->size() / 2) {
        return front_half[i];
    }
    else if (i == this->size() / 2) {
        if (this->size() % 2 == 0) {
            return back_half[0];
        }
        else {
            return front_half[i];
        }
    }
    else {
        if (this->size() % 2 == 0) {
            return back_half[i - this->size() / 2];
        }
        else {
            return back_half[i - 1 - this->size() / 2];
        }
    }
}

void Teque::push_back(int x) {
    back_half.emplace_back(x);
    if (front_half.size() == back_half.size() - 1) {
        front_half.push_back(back_half.front());
        back_half.pop_front();
    }
}

void Teque::push_front(int x) {
    front_half.emplace_front(x);
    if (front_half.size() == back_half.size() + 2) {
        back_half.push_front(front_half.back());
        front_half.pop_back();
    }
}

void Teque::push_middle(int x) {
    if (front_half.size() == back_half.size()) {
        front_half.emplace_back(x);
    }
    else {
        back_half.emplace_front(x);
    }
}

ostream& operator<<(ostream& os, Teque tq) {
    os << "{";
    for (int i = 0; i < tq.size() - 1; i++) {
        os << tq.get(i) << ", ";
    }
    os << tq.get(tq.size() - 1) << "}";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    Teque tq;

    for (int i = 0; i < N; i++) {
        string command;
        int num;
        cin >> command >> num;
        if (command == "push_back") {
            tq.push_back(num);
        }
        else if (command == "push_front") {
            tq.push_front(num);
        }
        else if (command == "push_middle") {
            tq.push_middle(num);
        }
        else if (command == "get") {
            cout << tq.get(num) << endl;
        }
    }
    return 0;
}