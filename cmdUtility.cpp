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
