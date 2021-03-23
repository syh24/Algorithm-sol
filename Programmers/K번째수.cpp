#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto x : commands) {
        vector<int> ret;
        int i = x[0]; int j = x[1]; int k = x[2];
        for (int n = i - 1; n < j; n++) {
            ret.push_back(array[n]);
            sort(ret.begin(), ret.end());
        }
        answer.push_back(ret[k - 1]);
    }
    return answer;
}