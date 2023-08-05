// combination sum

void help(int idx, int target, vector<int> &a, vector<vector<int>>& ans, vector<int>& ds){
    if(idx==a.size()){
        if(target==0) ans.push_back(ds);
        return;
    }

    //pick the element
    if(a[idx]<=target){
        ds.push_back(a[idx]);
        help(idx,target-a[idx],a,ans,ds);
        ds.pop_back();
    }

    help(idx+1,target,a,ans,ds);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    sort(ARR.begin(),ARR.end());
    vector<vector<int>> ans;
    vector<int> ds;
    help(0,B,ARR,ans,ds);
    return ans;
}