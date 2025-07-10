#include <bits/stdc++.h>
using namespace std;

  int main() {

    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int> arr(n);
      for(int i = 0;i < n;i++){
        cin >> arr[i] ;
      }
      int i = 0;
      while(i < n){
        int j = i+1;
        while(arr[i] > arr[j] && j < n){
          j++;
        }
        if(j < n){
          cout << arr[j] << " ";
        }
        else if(j == n){
          cout << -1 << " ";
        }
        i++;
      }
      cout << endl;
    }

    return 0;

  }