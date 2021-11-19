#include<bits/stdc++.h>
using namespace std;


typedef string::const_iterator State;
class ParseError {};

int number(State &begin){
  int num=0
  while(isdigit(*begin)){
    num*=10;
    num+= *begin - '0';
    begin++;
  }
  return num;
}


