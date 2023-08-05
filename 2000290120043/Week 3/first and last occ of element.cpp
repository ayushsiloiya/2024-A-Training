class Solution {
public:
    int firstOcc(vector<int>&nums, int target)
    {
        int res=-1;
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(nums[m]==target) {res = m;
            e=m-1;}
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }
        return res;
    }

    int lastOcc(vector<int>&nums, int target)
    {
        int res=-1;
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(nums[m]==target) {res = m;
            s=m+1;}
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0]=firstOcc(nums,target);
        ans[1]=lastOcc(nums,target);
        return ans;
        
    }
};