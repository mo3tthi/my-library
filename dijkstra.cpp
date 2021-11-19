#include<bits/stdc++.h>

using namespace std;


#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"
#define N 100000
#define F first
#define S second

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;



template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b; 
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct Node{
  vector<PII> edges;//first=cost,second=index

  bool visit;
  int cost;
};

vector<Node> mp;

void dijkstra(int st,int n){
  rep(i,n){
    mp[i].visit=false;
    mp[i].cost= INF;
  }
  priority_queue<PII> q;
  mp[st].cost=0;//スタート地点初期化
  q.push({0,st});
  while(!q.empty() ){
    PII p=q.top();
    int u=p.S;//確定させる頂点
    //cout<<u<<endl;
    q.pop();
    if(mp[u].visit) continue;//確定済ならば無視
    mp[u].visit=true;
    
    rep(i,mp[u].edges.size() ){
      //cout<<" "<<mp[u].edges[i].S<<endl;
      int v=mp[u].edges[i].S;
      if(!mp[v].visit){//確定済みでない頂点
	if(chmin(mp[v].cost,mp[u].cost+mp[u].edges[i].F) ){
	  q.push({-mp[v].cost,v});
	}
      }
    }
  }
}
    
      
    
signed main(){
  int n;
  cin>>n;
  mp.resize(n);
  rep(i,n){
    int u,k;
    cin>>u>>k;
    rep(j,k){
      int v,c;
      cin>>v>>c;
      mp[u].edges.push_back({c,v});
    }
  }
  
  dijkstra((int)0,n);
  rep(i,n){
    cout<<i<<" "<<mp[i].cost<<endl;
  }
  return 0;
}
