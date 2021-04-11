#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;

int pown(int x, int y){
    int res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
int dp[5000050];
int dp_bitmask(int mask, int n, vector<vector<int>> &grid){
       int cnt1=__builtin_popcount(mask);
       if(cnt1==n) return 0;
       if(dp[mask]!=-1) return dp[mask];
       int ans=inf;
    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
         ans=min(ans, dp_bitmask(mask|(1<<i), n, grid)+grid[cnt1][i]);
        }
    }
    return dp[mask]=ans;
}
void solve(){
    
   int n;
   cin>>n;

   vector<vector<int>> cost(n, vector<int>(n,0));

   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           int num;
           cin>>num;

           cost[i][j]=num;
       }
   }
       memset(dp, -1, sizeof(dp));
        int ans=dp_bitmask(0, n, cost);
        cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
