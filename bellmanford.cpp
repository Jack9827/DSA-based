// coded by Jai_Khatri

#include <bits/stdc++.h>

using namespace std;
//------------------------------
// Bellman Ford algo for negative weights and to detect negative cycle
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1 , 1e9);
    dist[src] = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    
    return dist[dest];
}
//---------------------------------

// main code starts here


int32_t main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        

        
    }


    return 0;

}   