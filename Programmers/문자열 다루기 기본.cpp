#include<bits/stdc++.h>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() == 4 || s.length() == 6) {
        int cnt = s.length();
        for (auto x : s) {
            if ('0' <= x && x <= '9') cnt--;
        }
        return cnt == 0 ? true : false;
    }
    else return false;
}