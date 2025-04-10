#include <bits/stdc++.h>
using namespace std;
long long dp[19][2][4];

// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define pb push_back
// #define endl '\n'

// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long fn(string &s,int i,int n,int tight,int valid){
    if(i==n) return 1;
    if(dp[i][tight][valid]!=-1) return dp[i][tight][valid];
    int limit= tight==1 ? s[i]-'0':9;
    long long ans=0;
    for(int k=0;k<=limit;k++){
        int updatevalid=valid+ (k==0 ? 0:1);
        if(updatevalid>=4) continue;
        ans+=fn(s,i+1,n,(tight&(k==s[i]-'0')),updatevalid);
    }
    return dp[i][tight][valid]=ans;
}

void solve() {
    long long l,r;
    cin>>l>>r;
    string li=to_string(l-1),ri=to_string(r);
    memset(dp,-1,sizeof(dp));
    long long right=fn(ri,0,ri.size(),1,0);
    memset(dp,-1,sizeof(dp));
    long long left=fn(li,0,li.size(),1,0);
    cout<<right-left<<endl;
}

int32_t main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
