class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultsize;
    vector<int> last;
    void dfs(int currnode, string& s, vector<int>& parent){
     int c = s[currnode] - 'a';
        int nearestAncestor = last[c];

        last[c] = currnode;
        for(int child: adj[currnode]){
            dfs(child, s, parent);
        }
        //back to currnode
        last[c] = nearestAncestor;

        //if currnode is root, it has no ancestor
        if(currnode != 0){
            int newparent = parent[currnode];//old parent

            if(nearestAncestor != -1){
                newparent = nearestAncestor;
            }
            parent[currnode] = newparent;

            resultsize[newparent] += resultsize[currnode];
        }
    }
        
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
       int n = parent.size();
       //parent[i]  = node
       //node is the parent of ith node
       //node ----> i 
       for(int i=1;i<n;i++){
        int u = parent[i];//u is the parent
        int v = i;
        adj[u].push_back(v);//u --> v
       }
       resultsize.assign(n,1);
       last.assign(26,-1);

       dfs(0,s,parent);

       return resultsize; 
    }
};