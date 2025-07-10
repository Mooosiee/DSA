#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int closestint, x;
    cin >> closestint >> x;
    
    
    int j = 0;
    while(arr[j] != x) {
        j++;
    }
    
    
    int i = j - 1, k = j + 1;

    
    while (closestint > 0) {
        if (i >= 0 && k < n) {
            
            if (abs(arr[i] - x) < abs(arr[k] - x) || (abs(arr[i] - x) == abs(arr[k] - x) && arr[i] < arr[k])) {
                ans.push_back(arr[i]);
                i--;
            } else {
                ans.push_back(arr[k]);
                k++;
            }
        } else if (i >= 0) {
            
            ans.push_back(arr[i]);
            i--;
        } else if (k < n) {
            
            ans.push_back(arr[k]);
            k++;
        }
        closestint--;
    }
    
    
    std::sort(ans.begin(), ans.end());
    

    for(auto it : ans) {
        cout << it << " "; 
    }
    return 0;
}
