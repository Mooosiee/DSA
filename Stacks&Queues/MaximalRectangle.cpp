/*
85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing 
only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
 
Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int>st1,st2;
        for(int i = 0;i < n;i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop();
            }
            if(!st1.empty()){
                pse[i] = st1.top();
            }
            st1.push(i);
        }
        for(int i = n-1;i >= 0;i--){

            while(!st2.empty() && arr[st2.top()] >= arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nse[i] = st2.top();
            }
            st2.push(i);
        }
        long long maxi = -1;
        for(int i = 0;i < n;i++){
            long long curr_area = 1LL * arr[i] * ((nse[i] - pse[i]) - 1);
            maxi = max(maxi,curr_area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>psum(rows,vector<int>(cols));

        for(int j = 0;j < cols;j++){
            int sum = 0;
            for(int i = 0;i < rows;i++){
                sum += (matrix[i][j] - '0');
                if(matrix[i][j] == '0') sum = 0;
                psum[i][j] = sum;
            }
        }
        int maxArea = 0;
        for(int i = 0;i < rows;i++){
            maxArea = max(maxArea,largestRectangleArea(psum[i]));
        }
        return maxArea;
    }
};