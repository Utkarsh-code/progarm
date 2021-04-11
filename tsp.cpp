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
unordered_map<int, vector<pi>> adj;
int dp[5000050];
int n;
int cnt_set_bit(int num){
    int ans=0;
    while(num>0){
     if(num&1) ans++;
     num=num>>1;
    }
    return ans;
}
int weight(int src, int des){

    for(auto i:adj[src]){
        int x=i.first;
        if(x==des) return i.second;
    }
    return -1;
}

int tsp(int mask, int idx){
    int cnt=cnt_set_bit(mask);
   // int cnt=__builtin_popcount(mask);
    if(cnt==n){
        return  weight(idx, 0);
    }
    if(dp[mask]!=-1) return dp[mask];
    int res=inf;
    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
            int wt=weight(idx, i);
            if(wt==-1) continue;
            res=min(res, tsp(mask|(1<<i), i)+wt);
        }
    }
    return dp[mask]=res;
}
void solve(){
      int  m;
      cin>>n>>m;

      for(int i=0; i<m; i++){
          int src, des, wt;
          cin>>src>>des>>wt;
          src--;
          des--;

          adj[src].push_back(make_pair(des, wt));
          adj[des].push_back(make_pair(src, wt));
      }
      memset(dp, -1, sizeof(dp));
    int  ans=tsp(1, 0);
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
