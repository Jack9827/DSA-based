#include <bits/stdc++.h>

using namespace std;
// kosaraju's algorithm
void dfs1(int node ,  map<int , list<int>> &adj  , map<int , bool> &vis , stack<int> &st)
{
    vis[node] = 1;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs1(nbr , adj , vis , st);
        }
    }
    
    st.push(node);
}

void dfs2(int node ,  map<int , list<int>> &adj  , map<int , bool> &vis)
{
    vis[node] = 1;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs2(nbr , adj , vis );
        }
    }
    
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    
    // adj list
    map<int , list<int>> adj;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    // topological sort
    map<int , bool> vis;
    stack<int> st;
    
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs1(i , adj , vis , st);
        }
    }
    
    // transpose of matrix
    map<int , list<int>> transpose;
    
     for(int i=0; i<v; i++){
         vis[i] = 0;
         
         for(auto nbr : adj[i]){
             transpose[nbr].push_back(i);
         }
     }
    
    // now do dfs from topologically sorted nodes
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            dfs2(top , transpose , vis);
        }
        
    }
    // count of strongly contected component
    return count;
}

int main(){



    return 0;
}