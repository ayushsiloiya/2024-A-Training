public class zeroOneKnapSack {
    public static int maxProfit(int w,int profit[],int weight[],int n){
        if(n==0 || w==0) return 0;
         if(weight[n-1]<w){
            return Math.max(profit[n-1]+maxProfit(w-weight[n-1],profit,weight,n-1 ),maxProfit(w,profit,weight,n-1 ));
        }
        else return maxProfit(w,profit,weight,n-1);
    }
    public static void main(String args[]) {
        int n=3,w=4;
        int profit[]={1,2,3};
        int weight[]={4,5,1};
        System.out.println(maxProfit(w,profit,weight,n));
    }
}