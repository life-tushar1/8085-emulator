#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
  FILE *fp;
  fp=freopen("load_mem.txt","r",stdin);
  int a,b;
  cin>>a>>b;
  cout<<a<<endl<<b;
  return 0;
}
