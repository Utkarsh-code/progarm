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
     int a, b;
     cin>>a>>b;

     string st;
     cin>>st;

     int n=st.length();
     int zero=0, one=0;
     if(n!=a+b){ cout<<-1<<"\n"; return;}
     for(int i=0; i<n/2; i++){
         if(st[i]!=st[n-i-1] && st[i]!='?'){ cout<<"-1\n"; return;}
         if(st[i]=='?' && st[n-i-1]!='?'){
             st[i]=st[n-i-1];
             if(st[i]=='0') zero++;
             else one++;
         }
         else if(st[i]!='?' && st[n-i-1]=='?'){
             st[n-i-1]=st[i];
             if(st[i]=='0') zero++;
             else one++;
         }
     }
       zero=0;
       one=0;
       int cnt=0;
     for(int i=0; i<n; i++){
         if(st[i]=='0') zero++;
         else one++;

         if(st[i]=='?') cnt++;
     }
     if(cnt==0){
         if(zero==a && one==b) {cout<<st<<"\n"; return;}
     }
    if(cnt%2==0){
        int rem=cnt/2;
        
    }
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
