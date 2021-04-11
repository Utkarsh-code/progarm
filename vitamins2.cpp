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

void solve(){
    int n;
    cin>>n;

    int dp[8];
    for(int i=0; i<8; i++) dp[i]=inf;
    dp[0]=0;
    
    for(int i=0; i<n; i++){
        int cost;
        cin>>cost;

        string st;
        cin>>st;
        
        int sum=0;
        for(auto ch:st){
           int nu=ch-'A';

           sum+=(1<<nu);
        }
        for(int i=0; i<8; i++){
            dp[i|sum]=min(dp[i|sum], dp[i]+cost);
        }
    }
    int ans=dp[7];
    if(ans==inf) ans=-1;
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
