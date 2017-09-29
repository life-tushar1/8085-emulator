#include "all.h"

using namespace std;
void exeLxi(string val,char op1,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{int dec;
  if(val[val.length()-1]=='H')
   dec=hexToint(val);
  else
   dec=stringToint(val);
   switchAssi(op1,dec,a,b,c,d,e,h,l);
}
void exeMov(string des,char src,map <int, int> &memory,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
//  cout<<"des = "<<des<<" src = "<<src<<endl;
  char dd=des[0];
  int dec;
//  cout<<" d "<<d<<endl;
//  cout<<"src "<<src<<endl;
  if(src=='M')
  {
  //  cout<<"rec"<<endl;
  dec=memory.find(*h)->second;
//  cout<<"dec "<<dec<<endl;
  switchAssi(dd,dec,a,b,c,d,e,h,l);
  }
  else if(dd!='M'&&src!='M')
  {
  //  cout<<"reached d!M src!m"<<endl;
    //cout<<"s="<<src<<"d="<<d<<endl;
    if(src=='A')
    {
      if(dd=='B')
      b=a;
      else if(dd=='C')
      c=a;
      else if(dd=='D')
      d=a;
      else if(dd=='E')
      e=a;
      else if(dd=='H')
      h=a;
      else if(dd=='L')
      l=a;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='B')
    {
      if(dd=='A')
      a=b;
      else if(dd=='C')
      c=b;
      else if(dd=='D')
      d=b;
      else if(dd=='E')
      e=b;
      else if(dd=='H')
      h=b;
      else if(dd=='L')
      l=b;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='C')
    {
      if(dd=='A')
      a=c;
      else if(dd=='B')
      b=c;
      else if(dd=='D')
      d=c;
      else if(dd=='E')
      e=c;
      else if(dd=='H')
      h=c;
      else if(dd=='L')
      l=c;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='L')
    {
      if(dd=='A')
      a=l;
      else if(dd=='B')
      b=l;
      else if(dd=='D')
      d=l;
      else if(dd=='E')
      e=l;
      else if(dd=='H')
      h=l;
      else if(dd=='C')
      c=l;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='D')
    {
      if(dd=='A')
      a=d;
      else if(dd=='B')
      b=d;
      else if(dd=='c')
      c=d;
      else if(dd=='E')
      e=d;
      else if(dd=='H')
      h=d;
      else if(dd=='L')
      l=d;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='E')
    {
      if(dd=='A')
      a=e;
      else if(dd=='B')
      b=e;
      else if(dd=='D')
      d=e;
      else if(dd=='C')
      c=e;
      else if(dd=='H')
      h=e;
      else if(dd=='L')
      l=e;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
    else if(src=='H')
    {
      if(dd=='A')
      a=h;
      else if(dd=='B')
      b=h;
      else if(dd=='D')
      d=h;
      else if(dd=='E')
      e=h;
      else if(dd=='C')
      c=h;
      else if(dd=='L')
      e=h;
      else
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
    }
  }
  if(dd=='M')
  {
    if(memory.count(*h)==0)
      memory.insert(pair <int, int> (*h,0));
    switchMemAccess(src,*h,memory,a,b,c,d,e,h,l);
}

}
