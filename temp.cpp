//474D
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1000000007;

int main(){
  ll t,k,templ,templ2,m;
  cin>>t>>k;
  m=-1;
  vector<pair<ll,ll>>v;
  for(ll i=0;i<t;i++){
    cin>>templ>>templ2;
    v.push_back(make_pair(templ,templ2));
    m=max(m,templ2);
  }
  ll dp[m+2][2];//last is R or last is W
  memset(dp,0,sizeof(dp));
  dp[1][0]=1;
  dp[0][0]=1;
  if(k==1){
    dp[1][1]=1;
  }
  for(ll i=2;i<m+1;i++){
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
    if(i>=k){
      dp[i][1]=(dp[i-k][0]+dp[i-k][1])%mod;
    }
  }/*
  for(ll i=0;i<m+1;i++){
    cout<<dp[i][0]<<" ";
  }
  cout<<endl;
  for(ll i=0;i<m+1;i++){
    cout<<dp[i][1]<<" "; 
  }
  cout<<endl;*/
  ll a[m+1];
  a[0]=0;
  for(ll i=1;i<m+1;i++){
    a[i]=(a[i-1]+dp[i][0]+dp[i][1])%mod;
  }
  for(auto x:v){
    cout<<(a[x.second]-a[x.first-1]+mod)%mod<<endl;
  }
  return 0;
}
