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
int dp[500010];
int decode(int idx, string st){
    
    if(idx==st.length()){
        //ans++;
        return 1;
    }
    if(dp[idx]!=-1) return dp[idx];
    int ans=0;
    for(int i=idx; i<idx+2 && i<st.length(); i++){
            string s=st.substr(idx, abs(i-idx)+1);
            int num=stoi(s);

            if(num==0) break;

            if(num>=1 && num<=26){
              ans+=decode(i+1, st);
            }
    }
    return dp[idx]=ans;
}
void solve(string st){
     memset(dp, -1, sizeof(dp));
    int ans=decode(0, st);
    cout<<ans<<"\n";

        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // int tc;
   // cin>>tc;
   // for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        while(1){
        string st;
        cin>>st;
        if(st[0]=='0') break;
        solve(st);
    }
    return 0;
}
