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
