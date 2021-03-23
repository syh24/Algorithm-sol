#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (auto x : arr) {
        if (!answer.empty() & answer.back() == x) continue;
        answer.push_back(x);
    }
    cout << "Hello Cpp" << endl;
    return answer;
}