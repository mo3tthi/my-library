

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
