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
int dx[3]={1, 1, 1};
int dy[3]={0, 1, -1};
int dp[110][110];
int stone(int row, int col, vector<vector<int>> & grid){
     if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int ans=ninf;
    for(int i=0; i<3; i++){
        int X=row+dx[i];
        int Y=col+dy[i];

        ans=max(ans, stone(X, Y, grid)+grid[row][col]);
    }
    return dp[row][col]=ans;
}
void solve(){
      int n, m;
      cin>>n>>m;

      vector<vector<int>> grid(n, vector<int>(m));
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              int num;
              cin>>num;
              grid[i][j]=num;
          }
      }
       
       int ans=ninf;
       memset(dp, -1, sizeof(dp));
      for(int i=0; i<m; i++){
          ans=max(ans,stone(0, i, grid));
      }
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
