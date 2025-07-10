#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++){
        int n , k;
        cin >> n >> k;
        int arr[n+1];
        for(int i = 1 ; i < n+1 ;i++){
            arr[i] = k;
            k++;
        }
        
        long long minum = INT_MAX;
       
        for(int a = 1 ; a < n+1 ;a++){
            long long x = 0;
            int j = 1;
            while(j <= a){
                x+=arr[j];
                j++;
            }
            int b = a+1;
            while(b < n+1){
                x-= arr[b];
                b++;
            }
            minum = min(minum,abs(x));
    
            
            
        }
        cout << minum << endl;
        
        
        

    }
}