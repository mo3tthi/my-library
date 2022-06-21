
struct Node{
  int parent,cost,rank;
}

struct UnionFind{
  vector<Node> data;

  UnionFind(int N){
    data.resize(N);
    rep(i,N){
      data[i].parent=-1;
      data[i].cost=0;
      data[i].rank=0;
    }
  }

  bool unite(int x, int y,int w) {
    
    w+=weight(x);
    w-=weight(y);
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x].rank > data[y].rank){swap(x, y);w*=-1;}
    if(data[x].rank==data[y].rank) data[x].rank++;
    data[y].parent = x;
    data[y].cost=w;
    return (true);
  }
 
  int find(int k) {
    if(data[k].parent < 0) return (k);
    int r=find(data[k].parent);
    data[k].cost+=data[data[k].parent].cost;
    return (data[k].parent = r);
  }

  bool isSame(int a,int b){
    return find(a)==find(b);
  }

  int weight(int k){
    find(k);
    return data[k].cost;
  }

  int diff(int x,int y){
    return weight(y)-weight(x);
  }
  
  
};
