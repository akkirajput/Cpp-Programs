#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;
    public :
    Graph(int v){
        this->v=v;
        adj=new vector<int>[v];
    }
    void addedge(int source,int destination)
    {
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }

    void display()
    {
        for(int i=0;i<v-1;i++)
        {
            cout<<i;
            for(int side:adj[i])
            cout<<"->"<<side;
            cout<<endl;
        }
    }

    bool dfs(int source,int dest)
    {
        stack<int> st;
        st.push(source);
        bool visited[v]={false};
        while(!st.empty())
        {
            int cur=st.top();
            st.pop();
            if(cur==dest)
            return true;

            for(int side:adj[cur])
            {
                if(!visited[side])
                {
                    visited[side]=true;
                    st.push(side);
                }
            }
        }
        return false;
    }



    int bfs(int source,int dest)
    {
        queue<int> q;
        int count=0;
        bool visited[v]={false};
        int parent[v];
        q.push(source);
        visited[source]=true;
        parent[source]=-1;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(cur==dest) break;
            
            for(int side:adj[cur])
            {
                if(!visited[side])
                {
                    visited[side]=true;
                    parent[side]=cur;
                   
                    q.push(side);
                }
            }
        }
        // cout<<"No path found "<<endl;
        // return false;
        int cur=dest;
        while(parent[cur]!=-1)
        {
            cout<<cur<<"->";
            cur=parent[cur];
            count++;
        }
        cout<<cur<<endl;
        return count;
    }
};

int main()
{
    
    int n,e;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;
    Graph g(n);
    cout<<"\nEnter "<<e<<" edges :\n";
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        g.addedge(s,d);
    }

    g.display();
    cout<<"Enter source and destination to find existance of path in between ";
    int source,dest;
    cin>>source>>dest;
    cout<<"Possible path? "<<g.bfs(source,dest);    
    cout<<"Possible ?"<<g.dfs(source,dest);
    return 0;

}