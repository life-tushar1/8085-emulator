#include "all.h"
using namespace std;
void switchAssi(char op1,int dec,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{//cout<<"dd="<<op1<<"dec="<<dec<<endl;
  switch(op1){
    case 'A':
    *a=dec;
    break;
    case 'B':
    *b=dec;
    break;
    case 'C':
    *c=dec;
    break;
    case 'D':
    *d=dec;
    break;
    case 'E':
    *e=dec;
    break;
    case 'H':
    *h=dec;
    break;
    case 'L':
    *l=dec;
    break;
    default:;
    cout<<"Syntax error"<<endl;
    exit(0);
  }
}
void switchMemAccess(char src,int des, map <int, int> &memory,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
//  cout<<"src = "<<src<<" des= "<<des<<endl;
  switch(src){
    case 'A':
    memory.at(des)=*a;
    break;
    case 'B':
    memory.at(des)=*b;
    break;
    case 'C':
    memory.at(des)=*c;
    break;
    case 'D':
    memory.at(des)=*d;
    break;
    case 'E':
    memory.at(des)=*e;
    break;
    case 'H':
    memory.at(des)=*h;
    break;
    case 'L':
    memory.at(des)=*l;
    break;
    default:
    cout<<"Syntax error"<<endl;
    exit(0);
  }
}
void switchRegAccess(char src,char dd,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
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
