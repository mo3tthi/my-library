#include<bits/stdc++.h>
using namespace std;


typedef string::const_iterator State;
class ParseError {};

struct P{
  double x,y;
  P(){}
  P(double x,double y) : x(x),y(y){}
  P operator + (P p){
    return P(add(x,p.x) , add(y,p.y) );
  }
  P operator - (P p){
    return P(add(x,-p.x) , add(y,-p.y) );
  }
  P operator * (double d){
    return P(x*d,y*d);
  }
  double dot(P p){
    return add(x*p.x,y*p.y);
  }
  double det(P p){
    return add(x*p.y,-y*p.x);
  }
};

bool comp(P &a,P &b){
  if(a.x!=b.x) return a.x<b.x;
  return a.y<b.y;
}

P convex_hull(vector<P> a,P b,int n){
  sort(a.begin(),a.end(),comp);
  int k=0;
  vector<P> q(n);
  rep(i,n){
    while(k>1 && (q[k-1]-q[k-2]).det(a[i]-q[k-1]) <= 0) k--;
    q[k++]=a[i];
  }

  for(int i=(n-2),t=k;i>=0;i--){
    while(k>t && (q[k-1]-q[k-2]).det(a[i]-q[k-1]) <= 0) k--;
    q[k++]=a[i];
  }
  q.resize(k-1);
  return q;
}


  
  





