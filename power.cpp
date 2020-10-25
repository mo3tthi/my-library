#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;

int power(int n,int m){
  int now=2;
  int num=1;
  while(n!=0){
    //cout<<n<<" "<<m<<endl;
    if(n%2!=0){
      num=(num*m)%MOD;
      
    }
    n/=2;
    m=(m*m)%MOD;
  }
  return num;
}

signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  cout<<power(b,a)<<endl;

  return 0;
}
