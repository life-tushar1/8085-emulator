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
   for(int i=hex.length()-2;i>=0;i--)
   {
     if(hex[i]>='0'&&hex[i]<='9')
     {//cout<<hex[i]<<" "<<charToint(hex[i])<<endl;
     s=s+(charToint(hex[i])*pow(16,hex.length()-2-i));}
     else
     s=s+(hexAlphaInt(hex[i])*pow(16,hex.length()-2-i));

   }
   return s;

 }
int stringToint(string str)
{
  int s=0;
  for(int i=0;i<str.length();i++)
  s=(s*10)+charToint(str[i]);
  return s;
}

int main()
{
  FILE *fp;
  fp=freopen("load_mem.txt","r",stdin);
  int n;
  cin>>n;
  //memory initialisation and load it into map
  while(n>0)
  {
    string mem="",val="";int dec,dec1;
    cin>>mem>>val;
    if(mem[mem.length()-1]=='H')
     dec=hexToint(mem);
    else
     dec=stringToint(mem);

    if(val[val.length()-1]=='H')
     dec1=hexToint(val);
    else
     dec1=stringToint(val);
    //cout<<dec<<endl;
    memory.insert(pair <int ,int> (dec,dec1));
    n--;
  }
  map <int, int> :: iterator it;
  for (it= memory.begin(); it != memory.end(); ++it)
    {
        cout  <<  '\t' << it->first <<  '\t' << it->second << '\n';
    }
  //cout<<a<<endl<<b;
  return 0;
}
