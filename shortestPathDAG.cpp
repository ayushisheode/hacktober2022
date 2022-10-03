#include<iostream>
#include<vector>
#include<stack>

using namespace std;

stack<int>s;
bool vis[10000];

void dfs(int node,vector<pair<int,int>>adj[])
{
    vis[node]=true;
    for(auto child:adj[node])
    {
        if(vis[child.first]==false)
            dfs(child.first,adj);
    }
    s.push(node);
}

void shortestPath(int node,int n,vector<pair<int,int>>adj[])
{
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
            dfs(i,adj);
    }

    int dist[n];
    // memset(dist,INT_MAX,sizeof(dist));
    for(int i=0;i<sizeof(dist);i++)
        dist[i]=INT_MAX;
    
    dist[0]=0;

    while(!s.empty())
    {
        int cur=s.top();
        s.pop();

        // if that node has been reached previously
        if(dist[cur]!=INT_MAX)
        {
            for(auto it:adj[cur])
            {
                if(dist[it.first]>dist[cur]+it.second)
                    dist[it.first]=dist[cur]+it.second;
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";

}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int> > adj[n];
    while(e--)
    {
        int x,y,wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y,wt});
    }
    // memset(vis,false,sizeof(vis));
    for(int i=0;i<sizeof(vis);i++)
        vis[i]=false;

    shortestPath(0,n,adj);
}