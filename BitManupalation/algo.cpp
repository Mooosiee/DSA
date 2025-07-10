#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int m , i;
  cin >> m;
  int n = s.length();
  cout << " hello ";
  for(int j = 0 ; j < m ;j++){ 
   cin >> i;
   reverse(s.begin() + (i-1) , s.end() - (i-1));
  }
  cout << s;
  
  return 0;

}