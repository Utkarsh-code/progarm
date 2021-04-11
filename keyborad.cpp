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
    
    int n, k;
    cin>>n>>k;

    string st;
    cin>>st;

    set<char> s;
    for(int i=0; i<k; i++){
        char num;
        cin>>num;
        s.insert(num);
    }
   /* int ans=0;
    for(int i=0; i<n; i++){
        int cnt=0;
       for(int j=i; j<n; j++){
           if(s.find(st[j])==s.end()) break;
           cnt++;
       }
       ans+=cnt;
    }
        cout<<ans<<"\n";*/

    int prev=0;
    int f[n+1];
    f[0]=0;

    for(int i=1; i<=n; i++){
        if(s.find(st[i-1])==s.end()){
            f[i]=f[i-1];
            prev=i;
        }
        else{
            f[i]=f[i-1]+abs(i-prev);
        }
    }
    cout<<f[n]<<"\n";
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
