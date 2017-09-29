#include <string>
#ifndef _cmdHeaders_h
#define _cmdHeaders_h
void exeLxi(std::string, char ,int *,int *,int *,int *,int *,int *,int *);
void exeMov(std::string,char,std::map <int, int> &,int *,int *,int *,int *,int *,int *,int *);
void exeInx(char,int*,int*);
void exeAdd(char op,std::map <int, int> &,int *,int *,int *,int *,int *,int *,int *);
#endif
