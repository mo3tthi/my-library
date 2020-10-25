#include <bits/stdc++.h> 
using namespace std;
#define FOR(i,l,r) for(int i=(l); i<(r); i++)
#define REP(i,n) FOR(i,0,n)
#define endl "\n"
#define debug(x) cout<<x<<endl;
typedef long long ll;
static const int INF = 1e9+7;

struct Edge {
  int to,cost;  //to 接続先　, cost 重み
  Edge(int to, int cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > Edge_List;  
Edge_List graph;  

vector<int> dist; //最短距離

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { 
    //nは頂点数,sは始まりの頂点

    dist = vector<int>(n,INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i=0; i<n; i++) {
        for (int v=0; v<n; v++) {
            for (int k=0; k<graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1) return true; // n回目にも更新があるならば負の閉路が存在している
                }
            }
        }
    }
  return false;
}


/*int main() {
  int n, m;
  cin >> n >> m;
  graph = Edge_List(n);
  
  for (int i=0; i<m; i++) {
    int from,to,cost;
    cin >>from>>to>>cost;
    graph[from].push_back(Edge(to, cost));
  }
  
  bellman_ford(n,0);

  for (int i=1; i<n; i++) {
    if (dist[i] != INF)
      cout<<"0から"<< i <<"へのコストは: "<<dist[i]<<endl;
  }
  
}
*/
