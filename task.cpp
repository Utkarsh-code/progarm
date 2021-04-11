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
int dp[5000100];
int  task(int mask, vector<vector<int>>& grid, int n){
    
   // if(mask==((1<<n)-1)) return 1;
    int cnt=__builtin_popcount(mask);
    if(cnt==n) return 1;
    if(dp[mask]!=-1) return dp[mask];
    //cout<<mask<<" ";
    int ans=0;
    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0 && grid[cnt][i]==1){
           // mask=(mask|(1<<i));

            ans+=task(mask|(1<<i), grid, n);
        }
    }
 //   cout<<ans<<" ";
   return dp[mask]=ans;
}
void solve(){
    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            grid[i][j]=num;
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans=task(0, grid, n);
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
