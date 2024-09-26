#include<iostream>
#include<vector>
using namespace std;
class Disjoint{
  vector<int> rank,parent,size;
  public:
  Disjoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++)
      {
          parent[i]=i;
      }
  }

  int findupar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findupar(parent[node]);
  }

  void unionbyrank(int u,int v)
  {
    int ulpu=findupar(u);
    int ulpv=findupar(v);
    if(ulpu==ulpv) return;
    if(rank[ulpu]>rank[ulpv])
    {
        parent[ulpv]=ulpu;
    }
    else if(rank[ulpu]<rank[ulpv]){
        parent[ulpu]=ulpv;
    }
    else{
        parent[ulpv]=ulpu;
        rank[ulpu]++;
    }
  }
  void unionbysize(int u,int v)
  {
    int ulpu=findupar(u);
    int ulpv=findupar(v);
    if(ulpu==ulpv) return;
    if(size[ulpu]>size[ulpv])
    {
        parent[ulpv]=ulpu;
        size[ulpu]+=size[ulpv];
    }
    else if(size[ulpu]<size[ulpv]){
        parent[ulpu]=ulpv;
        size[ulpv]+=size[ulpu];
    }
    else{
        parent[ulpv]=ulpu;
        rank[ulpu]++;
        size[ulpu]+=size[ulpv];
    }
  }
};

int main()
{
    Disjoint ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(2,6);
    if(ds.findupar(3)==ds.findupar(7))
    {
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;
    ds.unionbysize(3,7);
    if(ds.findupar(2)==ds.findupar(7))
    {
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;

}
