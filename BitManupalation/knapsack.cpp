#include <bits/stdc++.h>

using namespace std;

struct Item {
   int val;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.val / (double) a.weight;
         double r2 = (double) b.val / (double) b.weight;
         return r1 > r2;
      }
      
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].val;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].val / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
int main() {
   int n = 5, weight = 60;
   Item arr[n] = { {30,5},{40,10},{45,15},{77,22},{90,25} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum profit is "<< ans;
   return 0;
}