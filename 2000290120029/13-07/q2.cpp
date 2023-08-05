class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int j=0;
        ans.push_back(intervals[j]);
        for(int i=1;i<intervals.size();i++){
            if(ans[j][1]>=intervals[i][0]){
                ans[j][1]=max(intervals[i][1],ans[j][1]);
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};