#include <bits/stdc++.h>
  using namespace std;
string threesum(vector<int> arr,int sum,int n){
  for(int i = 0;i < n ;i++){
      for(int j = i+1; j < n;j++){
        for(int k = n-1 ; k >= j+1 ;k--){
          if(arr[i]+arr[j]+arr[k] == sum){
            return "Yes";
          }
        }
      }
    }
    return "No";
  
}
  int main() {

    int n , sum;
    cin >> n >> sum;
    vector<int> arr;
    for(int i = 0; i < n;i++){
      int el;
      cin >> el;
      arr.push_back(el);
    }
    cout << threesum(arr,sum,n);
    

    return 0;

  }