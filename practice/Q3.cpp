#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
class Solution{
  public:
  unordered_map<int,vector<int>> mpp;
  int height(Node*root){
   if(root == nullptr){
    return 0;
   }
   int lh = height(root->left);
   int rh = height(root->right);
   int ht = 1 + max(lh,rh);
   mpp[ht].push_back(root->data);
   return ht;
  }
  vector<vector<int>>
};