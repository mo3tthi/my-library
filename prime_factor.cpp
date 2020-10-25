#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

map<int,int> prime_factor(int n){
  map<int,int> mp;
  for(int i=2;i*i<=n;i+=2){
    while(n%i==0){
      mp[i]++;
      n/=i;
    }
    if(i==2) i--;
  }
  if(n!=1) mp[n]=1;
  return mp;
}


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  return 0;
}
