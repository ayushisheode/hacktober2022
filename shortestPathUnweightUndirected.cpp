#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

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

    int dist[nodes+1];
  

    for(int i=0;i<nodes+1;i++)
        dist[i]=INT_MAX;

    queue<int>q;
    q.push(0);
    dist[0]=0;

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        
        for(auto it:adj[cur])
        {
            if(dist[cur]+1<dist[it])
            {
                q.push(it);
                dist[it]=dist[cur]+1;
            }            
        }
    }

    for(int i=0;i<nodes;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
