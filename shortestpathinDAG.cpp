//Approch kya hai topological sort nikal ke stack mae rkh lenege 
//phir ek distance ka ban alenge 

#include<iostream>
#include<stack>
#include<list>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
class graph{
    public:
     unordered_map<int,list<pair<int,int>>>adj;

     void addedge(int u,int v,int weight)
     {
        pair<int,int>p=make_pair(v,weight);
        adj[u].push_back(p);
     }
     void printedge()
     {
        for(auto i:adj){
            cout<<i.first<<"  --> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
     }
    void dfs(int node,unordered_map<int,bool>&visited,stack<int> &s)
     {
        visited[node]=true;
        for(auto i:adj[node])
        {
            if(!visited[i.first])
            {
              dfs(i.first,visited,s);
            }
        }
        s.push(node);
     }
     void getshort(int src,vector<int>&distance,stack<int>&s){
               while(!s.empty())
        {
            int top=s.top();
            s.pop();
               if(distance[top]!=INT_MAX)
               {
                for(auto j:adj[top]){
                    if(distance[top]+j.second<distance[j.first])
                    {
                        distance[j.first]=distance[top]+j.second;
                    }
                }
               }
        }
     }
};
int main(){
    graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    g.printedge();
    unordered_map<int,bool>visited;
    int n=6;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited,s);
        }
    }
    int src=1;
    vector<int>distance(n);
        for(int i=0;i<n;i++)
        {
            distance[i]=INT_MAX;
            if(i==src)
            {
                distance[i]=0;
            }
        }
       g.getshort(src,distance,s);
       cout<<"answer is"<<endl;
       for(auto i:distance)
       {
        cout<<i<<" ";
       }cout<<endl;
    return 0;
}