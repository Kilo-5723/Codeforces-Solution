#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=2e5+5;

struct edge{
  int u,v,w;
};

edge e[maxn];
int main(){
  int tt;
  scanf("%d",&tt);
  while (tt--){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

  }
  return 0;
}