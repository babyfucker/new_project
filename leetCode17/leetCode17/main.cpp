//
//  main.cpp
//  leetCode17
//
//  Created by 张傲天 on 2017/2/7.
//  Copyright © 2017年 张傲天. All rights reserved.
//

//No. 130
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = (int)board.size();
        if (height == 0)
            return;
        int width = (int)board[0].size();
        vector<int> oXYPos(2,-1);
        vector<vector<int>> oPos;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 'O' && (i == 0||j == 0||i == height - 1||j == width - 1)) {
                    oXYPos[0] = i;
                    oXYPos[1] = j;
                    oPos.push_back(oXYPos);
                    board[i][j] = 'X';
                    find(oXYPos, board, oPos);
                }
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = 'X';
            }
        }
        for (int k = 0; k < oPos.size(); k++) {
            board[oPos[k][0]][oPos[k][1]] = 'O';
        }
    }
    void find(vector<int> p ,vector<vector<char>>& board, vector<vector<int>> &oPos) {;
        vector<int> oXYPos(2,-1);;
        if (p[0] > 0 && board[p[0] - 1][p[1]] == 'O') {
            oXYPos[0] = p[0] - 1;
            oXYPos[1] = p[1];
            oPos.push_back(oXYPos);
            board[oXYPos[0]][oXYPos[1]] = 'X';
            find(oXYPos, board, oPos);
        }
        if (p[1] > 0 && board[p[0]][p[1] - 1] == 'O') {
            oXYPos[0] = p[0];
            oXYPos[1] = p[1] - 1;
            oPos.push_back(oXYPos);
            board[oXYPos[0]][oXYPos[1]] = 'X';
            find(oXYPos, board, oPos);
        }
        if (p[0] < board.size() - 1 && board[p[0] + 1][p[1]] == 'O') {
            oXYPos[0] = p[0] + 1;
            oXYPos[1] = p[1];
            oPos.push_back(oXYPos);
            board[oXYPos[0]][oXYPos[1]] = 'X';
            find(oXYPos, board, oPos);
        }
        if (p[1] < board[0].size() && board[p[0]][p[1] + 1] == 'O') {
            oXYPos[0] = p[0];
            oXYPos[1] = p[1] + 1;
            oPos.push_back(oXYPos);
            board[oXYPos[0]][oXYPos[1]] = 'X';
            find(oXYPos, board, oPos);
        }
    }
};
class Solution_ {
public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int row=(int)board.size();
        if(!row)
            return;
        int col=(int)board[0].size();
        
        for(i=0;i<row;i++){
            check(board,i,0,row,col);
            if(col>1)
                check(board,i,col-1,row,col);
        }
        for(j=1;j+1<col;j++){
            check(board,0,j,row,col);
            if(row>1)
                check(board,row-1,j,row,col);
        }
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='1')
                    board[i][j]='O';
    }
    void check(vector<vector<char> >&vec,int i,int j,int row,int col){
        if(vec[i][j]=='O'){
            vec[i][j]='1';
            if(i>1)
                check(vec,i-1,j,row,col);
            if(j>1)
                check(vec,i,j-1,row,col);
            if(i+1<row)
                check(vec,i+1,j,row,col);
            if(j+1<col)
                check(vec,i,j+1,row,col);
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution_* s = new Solution_;
    vector<vector<char>> test = {{'X','X','X','X'},{'X','O','O','X'},{'X','O','O','X'},{'O','O','O','O'}};
    vector<vector<char>> test1 = {{'O','O'},{'O','O'}};
    s->solve(test);
    cout<<"keyile"<<endl;
    return 0;
}
