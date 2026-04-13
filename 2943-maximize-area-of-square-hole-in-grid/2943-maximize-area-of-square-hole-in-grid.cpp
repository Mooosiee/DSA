class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int max_h = 1;
        int max_v = 1;
        int curr_longest_h = 1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i = 1;i < hBars.size();i++){
            if((hBars[i] - hBars[i-1]) == 1){
                curr_longest_h++;
            }
            else{
                curr_longest_h = 1;
            }
            max_h = max(max_h,curr_longest_h);
        }
        int curr_longest_v = 1;
        for(int i = 1;i < vBars.size();i++){
            if((vBars[i] - vBars[i-1]) == 1){
                curr_longest_v++;
            }
            else{
                curr_longest_v = 1;
            }
            max_v = max(max_v,curr_longest_v);
        }
        int s = min(max_v,max_h)+1;
        return s*s;
    }
};