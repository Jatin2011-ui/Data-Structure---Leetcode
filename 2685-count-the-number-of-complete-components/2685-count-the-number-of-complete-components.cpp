class Solution {
    private:
    vector<int> DFS(int e , vector <vector<int>>&adj, vector<int>& nodes , unordered_set<int>& visited ){
        if (visited.count(e)) return {};
        visited.insert(e);
        nodes.push_back(e);

        for(auto& neigh: adj[e]){
            DFS (neigh , adj , nodes, visited );
        }
        return nodes;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(auto& e : edges){
            int u =e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        unordered_set<int>visited;
        for( int i=0; i<n; i++){
            if(visited.count(i)) continue;
            vector < int> nodes;
            vector<int> components = DFS (i, adj, nodes , visited);
            bool flag =true;
            for(auto& i: components){
                if ( adj [i].size() != components.size() -1 ){
                    flag = false;
                    break;

                }
            }
            if (flag ) cnt++;
        }
        return cnt;
    }
};