class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]>0){
            return {};
        }

        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int s=i+1,e=n-1;
            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                if(sum==0){
                    a.push_back({nums[i],nums[s],nums[e]});
                    int startval=nums[s];
                    while(s<e && nums[s]==startval){
                        s++;
                    }
                }else if(sum>0){
                    e--;
                }else{
                    s++;
                }
            }
        }
        return a;

    }
};