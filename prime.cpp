#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;

#define N 100000

int prime[N];

void eratosthenes(){
  rep(i,N) prime[i]=1;
  prime[0]=prime[1]=0;
  rep(i,n){
    if(prime[i]){
      for(int j=i+i;j<N;j+=i) prime[j]=0;
    }
  }
}

bool primeNumber(int n){
  if(n < 2) return false;
  else{
    for(int i = 2; i * i <= n; i++){
      if(n % i == 0) return false;
    }
    return true;
  }
}
