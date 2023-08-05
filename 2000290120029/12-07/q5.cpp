class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> um;
        int maxcount=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxcount=max(maxcount,i+1);
            }else if(um.find(sum)!=um.end()){
                maxcount=max(maxcount,i-um[sum]);
            }
            if(um.find(sum)==um.end())
              um[sum]=i;
        }
        return maxcount;
    }
};