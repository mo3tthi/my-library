#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long


int aa[200000],bb[200000],cc[2000000];
 
void t(){
  aa[0]=aa[1]=1;
  bb[0]=bb[1]=1;
  cc[1]=1;
  repi(i,2,200000){
    aa[i]=aa[i-1]*i%MOD;
    cc[i]=MOD-cc[MOD%i]*(MOD/i)%MOD;
    bb[i]=bb[i-1]*cc[i]%MOD;
  }
}
 
int calc(int n,int k){
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return aa[n]*(bb[k]*bb[n-k]%MOD)%MOD;
}
 


signed main(){
  int n,m;
  cin>>n>>m;
  t();
  cout<<calc(n,m)<<endl;

  return 0;
}
