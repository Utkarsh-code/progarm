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
vector<int> num;
vector<string> st;
int n;
int ans=inf;
vector<int> arr;
void check(){

    int a=0, b=0, c=0;
    
    int sum=0;
    for(int i=0; i<arr.size(); i++){
        sum+=num[arr[i]];
        string t=st[arr[i]];

        for(int j=0; j<t.length(); j++){
            if(t[j]=='A') a++;
            else if(t[j]=='B') b++;
            else if(t[j]=='C') c++;
        }
    }
    if(a>=1 && b>=1 && c>=1){
        ans=min(ans, sum);
    }
}
void fun(int idx){
    
    if(idx==n){
        check();
        return;
    }


    arr.push_back(idx);
    fun(idx+1);
    arr.pop_back();
    fun(idx+1);

    return;
}
void solve(){

    cin>>n;

    for(int i=0; i<n; i++){
         int a;
         cin>>a;
         num.push_back(a);
          string s;
          cin>>s;

          st.push_back(s);
    }

    fun(0);
    if(ans==inf) ans=-1;
    cout<<ans<<"\n";
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
