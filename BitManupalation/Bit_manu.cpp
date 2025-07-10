#include <bits/stdc++.h>
using namespace std;
void PB(int num)
{
    for (int i = 3; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        
        if(i&1){
            PB(i);
            cout << " - is Odd" << endl;
            

        }
        else{
            PB(i);
            cout << " - is Even" << endl;
            
        }
        cout << endl;
    }
}