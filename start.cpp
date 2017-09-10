#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<map>
#include<math.h>
using namespace std;
 map <int, int> memory;
 int a,b,c,d,e,h,l;
 bool zero,carry,sign,overflow;

int charToint(char c)
{
  int v=(int)(c-'0');
  return v;
}
int hexAlphaInt(char c)
{
  int v=(int)(c-'A');
  v=v+10;
  return v;
}

int hexToint(string hex)
 {int s=0;
   for(int i=hex.length()-1;i>=0;i--)
   {
     if(hex[i]>='0'&&hex[i]<='9')
     {//cout<<hex[i]<<" "<<charToint(hex[i])<<endl;
     s=s+(charToint(hex[i])*pow(16,hex.length()-1-i));}
     else
     s=s+(hexAlphaInt(hex[i])*pow(16,hex.length()-1-i));

   }
   return s;

 }


int main()
{
  FILE *fp;
  fp=freopen("load_mem.txt","r",stdin);
  int n;
  cin>>n;
  while(n>0)
  {
    string hex="";
    int val;
    cin>>hex>>val;
    int dec=hexToint(hex);
    cout<<dec<<endl;
    n--;
  }
  //cout<<a<<endl<<b;
  return 0;
}
