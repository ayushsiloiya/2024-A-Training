class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4){
            return {};
        }
        vector<vector<int>> a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int s=j+1,e=n-1;
                long long int newtarget=(long long)target-(nums[i]+nums[j]);
                while(s<e){
                    long long int sum=nums[s]+nums[e];
                    if(sum==newtarget){
                        a.push_back({nums[i],nums[j],nums[s],nums[e]});
                        int startval=nums[s];
                        while(s<e && startval==nums[s]){
                            s++;
                        }
                    }else if(sum<newtarget){
                        s++;
                    }else{
                        e--;
                    }
                }
            }
        }
        return a;
    }
};