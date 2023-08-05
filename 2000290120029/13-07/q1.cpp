class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> um;
        set<int> s;
        for(int i=0;i<n;i++){
            um[arr[i]]++;
        }
        for(auto num :um){
           s.insert(num.second);
        }
        if(s.size()==um.size()){
            return true;
        }else{
            return false;
        }
    }
};