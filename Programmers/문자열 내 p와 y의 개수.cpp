#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    for (auto x : s) {
        if (tolower(x) == 'p') cnt++;
        if (tolower(x) == 'y') cnt--;
    }
    return cnt == 0 ? true : false;
}