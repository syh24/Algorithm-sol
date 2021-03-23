#include<bits/stdc++.h>

using namespace std;

int cal(deque<pair<int, int>> q) {
    int sum = 0;
    for (auto x : q) {
        sum += x.first;
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> t) {
    deque<pair<int, int>> q;
    int time = 1;

    for (int i = 0; i < t.size(); i++) {
        int ww = cal(q);
        if (ww + t[i] <= weight) {
            q.push_back({ t[i], 0 });
            i++;
        }
        for (auto& k : q) k.second++;
        if (q.front().second == bridge_length) q.pop_front();
        i--;
        time++;
    }
    time += bridge_length - q.back().second;

    return time;
}