#include <bits/stdc++.h>
using namespace std;
int pred_row(vector<vector<int>>&mat,int mid,int j,int x){
    if(mat[mid][j] >= x){
        return 1;
    }
    else{
        return 0;
    }
}
int lower_bound_row(vector<vector<int>>&mat,int j,int n,int x){
    int l = -1, r = n;
    while(l+1 < r){
        int mid = l + (r-l)/2;
        if(pred_row(mat,mid,j,x) == 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if(r == n){
        return n-1;
    }
    else{
        return r;
    }
    
}
int pred_col(vector<vector<int>>&mat,int mid,int i,int x){
    if(mat[i][mid] >= x){
        return 1;
    }
    else{
        return 0;
    }
}
int lower_bound_col(vector<vector<int>>&mat,int i,int m,int x){
    int l = -1, r = m;
    while(l+1 < r){
        int mid = l + (r-l)/2;
        if(pred_col(mat,mid,i,x) == 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
    
}
int main() {
   int n,m,x;
   scanf("%d %d %d", &n, &m, &x);
   vector<vector<int>> mat(n,vector<int>(m)) ;
   for(int i = 0; i < n;i++){
       for(int j = 0;j < m;j++){
           scanf("%d", &mat[i][j]);
       }
   }
   int row = lower_bound_row(mat,0,n,x);
   if(mat[row][0] == x){
       cout << "YES";
       return 0;
   }
   else if(mat[row][0] < x && mat[row][m-1] < x){
       cout << "NO";
       return 0;
   }
   else{
       int col = lower_bound_col(mat,row,m,x);
       if(col < m && mat[row][col] == x){
           cout << "YES";
           return 0;
       }
   }
   cout << "NO";
   return 0;
   
}
