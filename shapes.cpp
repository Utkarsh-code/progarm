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
    
    int f[n+1];
    f[0]=1;
    f[1]=0;

    for(int i=2;i<=n; i++) f[i]=2*f[i-2];
    cout<<f[n]<<"\n";
   /* if(n&1) {cout<<"0\n"; return;}
    int ans=1<<(n/2);
    cout<<ans<<"\n";*/


        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
