#include "all.h"
using namespace std;

map <int, int> memory;
 int a=0,b=0,c=0,d=0,e=0,h=0,l=0;
 bool flag[4]={false};
int main()
{
  memoryInt(memory);
  FILE *fp2;
  fp2=freopen("instruction.txt","r",stdin);
  string cmd="";
  //cout<<cmd;
  while(cmd!="HLT")
  {
    cmd="";
    cin>>cmd;string val="";int dec;
    if(cmd=="LXI")
    {
      char op1;
      cin>>op1>>val;
      exeLxi(val,op1,&a,&b,&c,&d,&e,&h,&l);
    }
    else if(cmd=="MOV")
    {
    //  cout<<"rached"<<endl;
      string des="";char src;
      cin>>des;


    //  cout<<"des "<<des<<endl;
      if(des[des.length()-1]!=',')
      {
        cout<<"Syntax error"<<endl;exit(0);
      }
      cin>>src;
        exeMov(des,src,memory,&a,&b,&c,&d,&e,&h,&l);
    }
    else if(cmd=="INX")
    {//cout<<"reach h="<<h<<endl;
      char op;
      cin>>op;
      exeInx(op,&h,&l);
    }
    else if(cmd=="DCX")
    {//cout<<"reach h="<<h<<endl;
      char op;
      cin>>op;
      exeDcx(op,&h,&l);
    }
  else if(cmd=="ADD")
  {
    char op;
    cin>>op;
    exeAdd(op,memory,&a,&b,&c,&d,&e,&h,&l);

  }
  else if(cmd=="INR")
  {
    char op;
    cin>>op;
    exeInr(op,&a,&b,&c,&d,&e,&h,&l);
  }
  else if(cmd=="DCR")
  {
    char op;
    cin>>op;
    exeInr(op,&a,&b,&c,&d,&e,&h,&l);
  }


}
  display(memory,a,b,c,d,e,h,l);
  return 0;
}
