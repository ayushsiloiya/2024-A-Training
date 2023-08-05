int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> um;
    long long cxor=0; 
    int c=0;
    for(int i=0;i<A.size();i++){
        cxor^=A[i];
        if(cxor==B){
            c++;
        }
        if(um.find(cxor^B)!=um.end()){
            c+=um[cxor^B];
        }
        um[cxor]++;
    }
    return c;
}
