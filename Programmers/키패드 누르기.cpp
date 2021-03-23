#include<bits/stdc++.h>

using namespace std;


int grade(int now, int go) {
    if (now == 0) now = 11;
    if (now == '*') now = 10;
    if (now == '#') now = 12;
    if (go == 0) go = 11;
    int ni = (now - 1) / 3;
    int nj = (now - 1) % 3;
    int gi = (go - 1) / 3;
    int gj = (go - 1) % 3;

    return abs(gi - ni) + abs(gj - nj);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l1 = '*', r1 = '#';
    for (auto x : numbers) {
        if (x == 1 || x == 4 || x == 7) {
            l1 = x;
            answer += 'L';
        }
        else if (x == 3 || x == 6 || x == 9) {
            r1 = x;
            answer += 'R';
        }
        else {
            int gl = grade(l1, x);
            int gr = grade(r1, x);

            if (gl == gr) {
                if (hand == "left") {
                    l1 = x;
                    answer += 'L';
                }
                else {
                    r1 = x;
                    answer += 'R';
                }
            }
            else {
                if (gl < gr) {
                    answer += 'L';
                    l1 = x;
                }
                else {
                    answer += 'R';
                    r1 = x;
                }
            }
        }
    }
    return answer;
}