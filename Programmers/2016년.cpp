#include<bits/stdc++.h>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int start = 1;
    int day = 0;
    while (true) {
        if (start == a) break;
        if (start == 3 || start == 5 || start == 7 || start == 8 || start == 10 || start == 12) {
            day += 31;
        }
        else if (start == 2) {
            day += 29;
        }
        else {
            day += 30;
        }
        start++;
    }
    day += b;
    day = a == 1 ? day -= 1 : day;
    switch (day % 7) {
    case 1: answer += "SAT";
        break;
    case 2: answer += "SUN";
        break;
    case 3: answer += "MON";
        break;
    case 4: answer += "TUE";
        break;
    case 5: answer += "WED";
        break;
    case 6: answer += "THU";
        break;
    case 0: answer += "FRI";
        break;
    }
    return answer;
}