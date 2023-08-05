class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1,maxpro=nums[0],n=nums.size();
        for(int i=0;i<n;i++){
            pro*=nums[i];
            maxpro=max(pro,maxpro);
            if(pro==0){
                pro=1;
            }
        }
        pro=1;
        for(int i=n-1;i>=0;i--){
            pro*=nums[i];
            maxpro=max(pro,maxpro);
            if(pro==0){
                pro=1;
            }
        }
        return maxpro;
    }
};