#include<bits/stdc++.h>
using namespace std;

int color[10000]={0};

bool dfs(int cur,vector<int>adj[])
{
    if(color[cur]==-1) color[cur]=1;

    for(auto child:adj[cur])
    {
        if(color[child]==-1)
        {
            color[child]=1-color[cur];
            bool res=dfs(child,adj);
            if(res==false) return false;
        }
        else if(color[child]==color[cur])
            return false;
    }
    return true;
}

bool check(vector<int>adj[],int n)
{
    memset(color,-1,sizeof(color));
    for(int i=0;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,adj))
                return false;
        }
    }
    return true;
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int>adj[nodes+1];
    while(edges--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);        
    }

    if(check(adj,nodes))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
