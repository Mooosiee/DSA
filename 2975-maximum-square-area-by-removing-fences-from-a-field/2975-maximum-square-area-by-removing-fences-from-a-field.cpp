class Solution {
public:
    int M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int> widths;
        
        for(int i = 0;i < vFences.size();i++){
            for(int j = i + 1;j < vFences.size();j++){
                int w = vFences[j]-vFences[i];
                widths.insert(w);
            }
        }
        int maxS = 0;
        for(int i = 0;i < hFences.size();i++){
            for(int j = i + 1;j < hFences.size();j++){
                int h = hFences[j]-hFences[i];
                if(widths.find(h) != widths.end()){
                    maxS = max(maxS,h);
                }
                
            }
        }
        return maxS == 0 ? -1 : (1LL*maxS*maxS) % M;

    }
};