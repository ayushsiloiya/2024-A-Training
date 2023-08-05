class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int xv=0,x=0,y=0,rmsb;
        for(int i=0;i<arr.size();i++){
            xv=xv^arr[i]^(i+1);
        }
        rmsb=xv&~(xv-1);
        for(int i=0;i<arr.size();i++){
            if(arr[i]&rmsb){
                x^=arr[i];
            }else{
                y^=arr[i];
            }
            
            if((i+1)&rmsb){
                x^=(i+1);
            }else{
                y^=(i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                return {x,y};
            }else if(arr[i]==y){
                return {y,x};
            }
        }
    }
};