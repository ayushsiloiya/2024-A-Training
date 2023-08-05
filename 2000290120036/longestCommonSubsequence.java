public class longestCommonSubsequence
{
    //Function to find the length of longest common subsequence in two strings.
    static int helper(int a,int b,String small,String large){
        // if(a==small.length() || b==large.length()) return 0;
        // if(small.charAt(a)==large.charAt(b)){
        //     return 1+helper(a+1,b+1,small,large);
        // }
        // else return Math.max(helper(a+1,b,small,large),
        // helper(a,b+1,small,large));
        int s=small.length();
        int l=large.length();
        int t[][]=new int[s+1][l+1];
        for(int i=s-1;i>=0;i--){
            for(int j=l-1;j>=0;j--){
                if(small.charAt(i)==large.charAt(j)){
                    t[i][j]=1+t[i+1][j+1];
                }
                else t[i][j]=Math.max(t[i+1][j],t[i][j+1]);
            }
        }
        return t[0][0];
    }
    static int lcs(int x, int y, String s1, String s2)
    {
        if(x>y) return helper(0,0,s2,s1);
        else return helper(0,0,s1,s2);
        
    }
    
}