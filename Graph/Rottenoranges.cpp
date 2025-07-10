#include<bits/stdc++.h>
using namespace std;
//this code is good but we should never alter the given input/data (it is not professional)(but i thought i was saving space)
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid){
            int m = grid.size();
            int n = grid[0].size();
            int fresh_count = 0;
            pair<int,int> init;
            for(int i = 0 ; i < m;i++){
                for(int j = 0;j < n;j++){
                    if(grid[i][j] == 1){
                        fresh_count++;
                    }
                }
            }
            queue<pair<pair<int,int>,int>> q;
            for(int i = 0 ; i < m;i++){
                for(int j = 0;j < n;j++){
                    if(grid[i][j] == 2){
                        q.push({{i,j},0});
                    }
                }
            }
            int max_time = 0;
            while(!q.empty()){
                pair<pair<int,int>,int> node = q.front();
                q.pop();
                int i = node.first.first;
                int j = node.first.second;
                if(i-1 >= 0){
                    if(grid[i-1][j] == 1){
                        grid[i-1][j] = 2;
                        q.push({{i-1,j},node.second + 1});
                        fresh_count--;
                    }
                }
                if(j-1 >= 0){
                    if(grid[i][j - 1] == 1){
                        grid[i][j - 1] = 2;
                        q.push({{i,j - 1},node.second + 1});
                        fresh_count--;
                    }
                }
                if(i+1 < m){
                    if(grid[i+1][j ] == 1){
                        grid[i+1][j] = 2;
                        q.push({{i+1,j},node.second + 1});
                        fresh_count--;
                    }
                }
                if(j+1 < n){
                    if(grid[i][j+1] == 1){
                        grid[i][j+1] = 2;
                        q.push({{i,j+1},node.second + 1});
                        fresh_count--;
                    }
                }
                maxtime = node.second;
                
            }
            if(fresh_count){
                return -1;
            }
            return max_time;
        }
    };
    //Better code
    