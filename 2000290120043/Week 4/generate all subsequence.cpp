// generate all subsequence (leetcode)
class Solution {
public:

    void solve(int idx, vector<int> list, vector<int> nums, vector<vector<int>>& ans){
        if(idx>=nums.size()) {
            ans.emplace_back(list);
            return;
        }

        solve(idx+1,list,nums,ans);
        list.emplace_back(nums[idx]);
        solve(idx+1,list,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        solve(0,list,nums,ans);
        return ans;
    }
};