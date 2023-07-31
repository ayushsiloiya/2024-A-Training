class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0 ||n==1){
            return;
        }
        int i=n-2,j=n-1;
        while(i>=0 && nums[i+1]<=nums[i]) i--;
        if(i>=0){
            while(nums[i]>=nums[j]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};