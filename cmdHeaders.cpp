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
  char dd=des[0];
  int dec;
  if(src=='M')
  {
  dec=memory.find(*h)->second;
  switchAssi(dd,dec,a,b,c,d,e,h,l);
  }
  else if(dd!='M'&&src!='M')
  {
      switchRegAccess(src,dd,a,b,c,d,e,h,l);
  }
  if(dd=='M')
  {
    if(memory.count(*h)==0)
      memory.insert(pair <int, int> (*h,0));
    switchMemAccess(src,*h,memory,a,b,c,d,e,h,l);
  }
}
void exeInx(char op,int *h,int *l)
{
  if(op=='H')
  *h+=1;
  else if(op=='L')
  *l+=1;
  else
  {
    cout<<"Syntax error"<<endl;
    exit(0);
  }
}
void exeInr(char op,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
  switch(op)
  {
    case 'A':
    *a+=1;
    break;
    case 'B':
    *b+=1;
    break;
    case 'C':
    *c+=1;
    break;
    case 'D':
    *d+=1;
    break;
    case 'E':
    *e+=1;
    break;
    case 'M':
    *h+=1;
    break;
    default:
    cout<<"Syntax error"<<endl;
    exit(0);

  }
}
void exeDcr(char op,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
  switch(op)
  {
    case 'A':
    *a-=1;
    break;
    case 'B':
    *b-=1;
    break;
    case 'C':
    *c-=1;
    break;
    case 'D':
    *d-=1;
    break;
    case 'E':
    *e-=1;
    break;
    case 'M':
    *h-=1;
    break;
    default:
    cout<<"Syntax error"<<endl;
    exit(0);

  }
}
void exeDcx(char op,int *h,int *l)
{
  if(op=='H')
  *h-=1;
  else if(op=='L')
  *l-=1;
  else
  {
    cout<<"Syntax error"<<endl;
    exit(0);
  }
}
void exeAdd(char op,map <int, int> &memory,int *a,int *b,int *c,int *d,int *e,int *h,int *l)
{
  int dec;
  switch(op)
  {
    case 'M':
     dec=memory.find(*h)->second;
    *a=*a+dec;
    break;
    case 'B':
    *a=*a+*b;
    break;
    case 'C':
    *a=*a+*c;
    break;
    case 'D':
    *a=*a+*d;
    break;
    case 'H':
    *a=*a+*h;
    break;
    case 'L':
    *a=*a+*l;
    break;
    default:
    cout<<"Syntax error"<<endl;
    exit(0);
  }
}
