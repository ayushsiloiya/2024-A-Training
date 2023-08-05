public class unboundedKnapSack{
    
    static int knapSack(int n, int w, int profit[], int weight[])
    {
        // code here
    //   if(n==0 || w==0 ) return 0;
    //   if(weight[n-1]<= w){
    //       return Math.max(profit[n-1]+knapSack(n,w-weight[n-1]
    //       ,profit,weight),knapSack(n-1,w,profit,weight));
    //   }
    //   else return knapSack(n-1,w,profit,weight);
       int t[][]=new int[n+1][w+1];
       for(int i=1;i<=n;i++){
           for(int j=1;j<=w;j++){
               if(weight[i-1]<=j){
                   t[i][j]=Math.max(profit[i-1]+t[i][j-weight[i-1]]
                   ,t[i-1][j]);
               }
               else t[i][j]=t[i-1][j];
           }
       }
       return t[n][w];
    }
}