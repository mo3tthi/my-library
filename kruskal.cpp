#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1e18 + 10
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

struct UnionFind{
  vector<int> data;

  UnionFind(int N){
    data.assign(N,-1);
  }

 bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  bool isSame(int a,int b){
    return find(a)==find(b);
  }
  int size(int k) {
    return (-data[find(k)]);
  }
};

struct Edge{
  int u,v,cost;
};

bool Kruskalcomp(Edge &a,Edge &b){
  return a.cost<b.cost;
}

struct Kruskal{
  int v;
  
  int sum;
  vector<Edge> edges;
  
  void init(){
    sort(edges.begin(),edges.end(),Kruskalcomp );
    UnionFind uf=UnionFind(v);
    sum=0;
    for(auto e:edges){
      if(!uf.isSame(e.u,e.v) ){
	uf.unite(e.u,e.v);
	sum+=e.cost;
      }
    }
  }
  Kruskal(const vector<Edge> &edge,int x) : edges(edge),v(x) {init();}
  
};

signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);


  return 0;
}
