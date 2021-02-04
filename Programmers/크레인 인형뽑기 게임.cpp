#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int cnt = 0;
    vector<int> v;
    for (int l = 0; l < moves.size(); l++) {
        bool flag = false;
        int a = moves[l];
        a--;
        int x = 0;
        while (true) {
            if (board[x][a]) break;
            if (x == board.size() - 1) {
                flag = true;
                break;
            }
            if (!board[x][a]) x++;
        }
        if (flag) continue;
        v.push_back(board[x][a]);
        board[x][a] = 0;
        int n = v.size() - 1;
        if (v[n] == v[n - 1]) {
            cnt += 2;
            v.pop_back();
            v.pop_back();
        }
    }
    return cnt;
}