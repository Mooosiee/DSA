#include <bits/stdc++.h>
  using namespace std;

  int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
      cin >> arr[i];
    }
    int max_stolen = 0;
    auto max_it = max_element(arr.begin(), arr.end());
    int ind = distance(arr.begin() , max_it);
    int i = ind - 2;
    int j = ind + 2;
    while(i >= 0 && j < n){
      max_stolen += arr[i] + arr[j];
      i = i - 2;j = j + 2;
      
    }
    while(i >= 0){
      max_stolen += arr[i];
      i -=2;
    }
    while(j < 0){
      max_stolen += arr[j];
      j +=2;
    }
    cout << max_stolen;
    return 0;

  }