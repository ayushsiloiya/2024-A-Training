class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i].push_back(1);
            long long int val=1;
            for(int j=1;j<i+1;j++){
                val*=(i+1-j);
                val/=j;
                ans[i].push_back(val);
            }
        }
        return ans;
    }
};