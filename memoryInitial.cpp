#include "all.h"
using namespace std;
void memoryInt(map <int, int> &memory)
{cout<<"Memory initialisation Begin"<<endl;
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
  cout<<"Memory initialisation Done"<<endl;
}
