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
#define endl "\n"

int A[300000],B[300000];


//Aに入るのは、Sのi文字目から何文字がtの接頭辞と一致するか

void zalgorithm(string S,string t){
  int i = 0, j = 0;
  while (i+j < S.size() && j < t.size() && t[j] == S[i+j]) ++j;
  A[i] = j;
  if (j != 0){
    int k = 1;
    while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
  }
  i=1;j=0;
  while (i < S.size()) {
    while (i+j < S.size() && j < t.size() && t[j] == S[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
}

void rzalgorithm(string S,string t){
  int i = 0, j = 0;
  reverse(t.begin(),t.end() );
  reverse(S.begin(),S.end() );
  // cout<<t<<endl;
  while (i+j < S.size() && j < t.size() && t[j] == S[i+j]) ++j;
  B[i] = j;
  if (j != 0){
    int k = 1;
    while (i+k < S.size() && k+B[k] < j) B[i+k] = B[k], ++k;
  }
  i=1;j=0;
  while (i < S.size()) {
    while (i+j < S.size() && j < t.size() && t[j] == S[i+j]) ++j;
    B[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+B[k] < j) B[i+k] = B[k], ++k;
    i += k; j -= k;
  }
}
