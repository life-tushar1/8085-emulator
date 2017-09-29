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
    switchRegAccess(src,dd,a,b,c,d,e,h,l);
  }
  if(dd=='M')
  {
    if(memory.count(*h)==0)
      memory.insert(pair <int, int> (*h,0));
    switchMemAccess(src,*h,memory,a,b,c,d,e,h,l);
}

}
