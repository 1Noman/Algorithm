#include<bits/stdc++.h>
using namespace std;
const int N=999;
vector<int>parent(N);

void makeset(int v)
{   //cout<<" makeset: "<< v<< endl;
    parent[v]=v;

}
int findset(int v)
{
    cout<< " findset: "<< v<<endl;
    if(v==parent[v])
    {
       // cout<< " f if: "<< parent[v]<< endl;
        return v;
    }
    else{
       // cout<< " f else: "<< parent[v]<< endl;
        return findset(parent[v]);
        
    }
}
void unionset(int a,int b)
{
    int x=findset(a);
    int y=findset(b);
   // cout<< "x "<< x << "y "<<y<< endl;
    if(x!=y)
    {
        parent[y]=x;
      //  cout<<"parent[y]:" << parent[y]<< endl;
    }
}
int main()
{
    bool flag=false;
    for(int i=0;i<N;i++)
    {
        makeset(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        edges.push_back({u,v});
       
       // edges[u].push_back(v); Not working
    }
    for(auto i:edges)
    {
       // cout<< " for u v: "<<  i[0]<< " "<< i[1]<< endl;
        int u=i[0];
        int v=i[1];
        int x=findset(u);
        int y=findset(v);
       // cout<< " x: Y" << x << " "<< y<< endl;
        if(x==y)
        {
           // cout<< " flag"<< endl;
         flag=true;
        }
        else
        {
           // cout<<" unious e:"<< endl;
            unionset(u,v);
        }

    }
    if(flag==true)
    {
        cout<<"Cycle";
    }
    else
    {
        cout<<"Not cycle";
    }


    return 0;
}
