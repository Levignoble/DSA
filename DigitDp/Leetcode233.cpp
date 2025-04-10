class Solution {
public:
int dp[10][2][10];
    int solve(string &s,int i,int n, int tight,int cnt){
        if(i==n) return cnt;
        if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];
        int ans=0;
        int limit=tight==1 ? s[i]-'0':9;
        for(int k=0;k<=limit;k++){
            int updatecnt=k==1 ? cnt+1:cnt;
            ans+=solve(s,i+1,n,(tight&(k==limit)),updatecnt);
        }
        return dp[i][tight][cnt]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size(),1,0);
    }
};
