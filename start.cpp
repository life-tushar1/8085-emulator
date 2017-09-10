#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<map>
#include<math.h>
using namespace std;
 map <int, int> memory;
 int a=0,b=0,c=0,d=0,e=0,h=0,l=0;
 bool flag[4]={false};

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

void display()
{
  map <int, int> :: iterator it;
    for (it= memory.begin(); it != memory.end(); ++it)
      {
          cout << it->first <<  '\t' << it->second << '\n';
      }
  cout<<"A "<<a<<endl<<"B "<<b<<endl<<"C "<<c<<endl<<"D "<<d<<endl<<"E "<<e<<endl<<"H "<<h<<endl<<"L "<<l<<endl;
}

int main()
{
  FILE *fp,*fp2;
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
  fclose(fp);
  //cout<<"reached";
  fp=freopen("instruction.txt","r",stdin);
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
      if(val[val.length()-1]=='H')
       dec=hexToint(val);
      else
       dec=stringToint(val);
       switch(op1){
         case 'A':
         a=dec;
         break;
         case 'B':
         b=dec;
         break;
         case 'C':
         c=dec;
         break;
         case 'D':
         d=dec;
         break;
         case 'E':
         e=dec;
         break;
         case 'H':
         h=dec;
         break;
         case 'L':
         l=dec;
         break;
         default:
         cout<<"Syntax error"<<endl;
         exit(0);
       }
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
      char d=des[0];
    //  cout<<" d "<<d<<endl;
    //  cout<<"src "<<src<<endl;
      if(src=='M')
      {
      //  cout<<"rec"<<endl;
      dec=memory.find(h)->second;
    //  cout<<"dec "<<dec<<endl;
        switch(d){
          case 'A':
          a=dec;
          break;
          case 'B':
          b=dec;
          break;
          case 'C':
          c=dec;
          break;
          case 'D':
          d=dec;
          break;
          case 'E':
          e=dec;
          break;
          case 'H':
          h=dec;
          break;
          case 'L':
          l=dec;
          break;
          default:
          cout<<"Syntax error"<<endl;
          exit(0);
        }

      }
      else if(d!='M'&&src!='M')
      {
        cout<<"reached"<<endl;
      //  cout<<"s="<<src<<"d="<<d<<endl;
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
      if(d=='M')
      {
        switch(src){
          case 'A':
          memory.at(h)=a;
          break;
          case 'B':
          memory.at(h)=b;
          break;
          case 'C':
          memory.at(h)=c;
          break;
          case 'D':
          memory.at(h)=d;
          break;
          case 'E':
          memory.at(h)=e;
          break;
          case 'H':
          memory.at(h)=h;
          break;
          case 'L':
          memory.at(h)=l;
          break;
          default:
          cout<<"Syntax error"<<endl;
          exit(0);
      }

    }
  //cout<<cmd<<endl;
  }
}
  display();
  return 0;
}
