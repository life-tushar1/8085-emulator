#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<map>
#include<math.h>
#include "cmdUtility.h"
using namespace std;
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

void display(map <int, int> memory,int a,int b,int c,int d,int e,int h,int l)
{
  map <int, int> :: iterator it;
    for (it= memory.begin(); it != memory.end(); ++it)
      {
          cout << it->first <<  '\t' << it->second << '\n';
      }
  cout<<"A "<<a<<endl<<"B "<<b<<endl<<"C "<<c<<endl<<"D "<<d<<endl<<"E "<<e<<endl<<"H "<<h<<endl<<"L "<<l<<endl;
}
