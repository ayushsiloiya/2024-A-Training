class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,st=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                st=mid;
                e=mid-1;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        if(st==-1) return {-1,-1};
        int end=st;
        for(int i=st+1;i<nums.size();i++){
            if(nums[i]==target) end++;
        }
        return {st,end};
    }
};