#include <bits/stdc++.h>
using namespace std;

// not aplicapable for -ve weights
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src) {
    // adj list
    int n = vertices;
    vector<vector<pair<int , int>>> adj(n+1);
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
    
    vector<int> dist(vertices , INT_MAX);
    
     
    
    set<pair<int , int>> st;
    // src node into the set
    st.insert({0 , src});
    dist[src] = 0;
    
    while(!st.empty()){
        pair<int ,int> top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        st.erase(st.begin());
        
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find({dist[neighbour.first] , neighbour.first});
                
                if(record != st.end())
                    st.erase(record);
                    
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert({dist[neighbour.first]  , neighbour.first});
            }
        }
    }
    // respective index will return it's minimum distance from source
    return dist;
}


int main(){


    return 0;
}