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
      /*if(val[val.length()-1]=='H')
       dec=hexToint(val);
      else
       dec=stringToint(val);
       switchAssi(op1,dec,&a,&b,&c,&d,&e,&h,&l);*/
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
    //  cout<<"des = "<<des<<" src = "<<src<<endl;
      char dd=des[0];
    //  cout<<" d "<<d<<endl;
    //  cout<<"src "<<src<<endl;
      if(src=='M')
      {
      //  cout<<"rec"<<endl;
      dec=memory.find(h)->second;
    //  cout<<"dec "<<dec<<endl;
      switchAssi(dd,dec,&a,&b,&c,&d,&e,&h,&l);
      }
      else if(dd!='M'&&src!='M')
      {
      //  cout<<"reached d!M src!m"<<endl;
        //cout<<"s="<<src<<"d="<<d<<endl;
        if(src=='A')
        {
          if(d=='B')
          b=a;
          else if(d=='C')
          c=a;
          else if(d=='D')
          d=a;
          else if(d=='E')
          e=a;
          else if(d=='H')
          h=a;
          else if(d=='L')
          l=a;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='B')
        {
          if(d=='A')
          a=b;
          else if(d=='C')
          c=b;
          else if(d=='D')
          d=b;
          else if(d=='E')
          e=b;
          else if(d=='H')
          h=b;
          else if(d=='L')
          l=b;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='C')
        {
          if(d=='A')
          a=c;
          else if(d=='B')
          b=c;
          else if(d=='D')
          d=c;
          else if(d=='E')
          e=c;
          else if(d=='H')
          h=c;
          else if(d=='L')
          l=c;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='L')
        {
          if(d=='A')
          a=l;
          else if(d=='B')
          b=l;
          else if(d=='D')
          d=l;
          else if(d=='E')
          e=l;
          else if(d=='H')
          h=l;
          else if(d=='C')
          c=l;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='D')
        {
          if(d=='A')
          a=d;
          else if(d=='B')
          b=d;
          else if(d=='c')
          c=d;
          else if(d=='E')
          e=d;
          else if(d=='H')
          h=d;
          else if(d=='L')
          l=d;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='E')
        {
          if(d=='A')
          a=e;
          else if(d=='B')
          b=e;
          else if(d=='D')
          d=e;
          else if(d=='C')
          c=e;
          else if(d=='H')
          h=e;
          else if(d=='L')
          l=e;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
        else if(src=='H')
        {
          if(d=='A')
          a=h;
          else if(d=='B')
          b=h;
          else if(d=='D')
          d=h;
          else if(d=='E')
          e=h;
          else if(d=='C')
          c=h;
          else if(d=='L')
          e=h;
          else
          {
            cout<<"Syntax error"<<endl;exit(0);
          }
        }
      }
      if(dd=='M')
      {
        if(memory.count(h)==0)
          memory.insert(pair <int, int> (h,0));
        switchMemAccess(src,h,memory,&a,&b,&c,&d,&e,&h,&l);
    }

    }
    else if(cmd=="INX")
    {//cout<<"reach h="<<h<<endl;
      char op;
      cin>>op;
      if(op=='H')
      h++;
      else if(op=='L')
      l++;
      else
      {
        cout<<"Syntax error"<<endl;
        exit(0);
      }
    //  cout<<"yo h="<<h<<endl;
  //cout<<cmd<<endl;
  }
  else if(cmd=="ADD")
  {
    char op;
    cin>>op;
    switch(op)
    {
      case 'M':
      dec=memory.find(h)->second;
      a=a+dec;
      break;
      case 'B':
      a=a+b;
      break;
      case 'C':
      a=a+c;
      break;
      case 'D':
      a=a+d;
      break;
      case 'H':
      a=a+h;
      break;
      case 'L':
      a=a+l;
      break;
      default:
      cout<<"Syntax error"<<endl;
      exit(0);
    }
  }

}
  display(memory,a,b,c,d,e,h,l);
  return 0;
}
