class Solution {
public:
    typedef pair<int, int> P; //wt , idx
    typedef tuple<long, int , int> T;//finTime , wt ,idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        //free servers (wt, idx)
        priority_queue<P, vector<P>, greater<P>> freeservers;

        //busy servers {finTime, wt, idx}
        priority_queue<T, vector<T>, greater<T>> busyservers;

        for(int i=0;i<n;i++){// n
            freeservers.push({servers[i], i});  //log(n)
        }
        vector<int> result(m);

        for(int i=0;i<m;i++){
            //move busy server to  free servers if they are free by ith time
            //move servers -----> free servers
            while(!busyservers.empty() && get<0>(busyservers.top()) <= i){
                auto[finTime, wt, idx] = busyservers.top();
                busyservers.pop();
                freeservers.push({wt, idx});
            }
            //free_server ----> busy_server
            if(freeservers.empty()){
                auto[finTime, wt, idx] = busyservers.top();
                busyservers.pop();
                result[i] = idx;
                busyservers.push({finTime + tasks[i], wt, idx});
            }else{ // free server ---> busy server {all server move to busy for all tasks}
                auto[wt, idx] = freeservers.top();
                freeservers.pop();
                result[i] = idx;
                busyservers.push({i+ tasks[i], wt, idx});
            }
        }
        //totoal m tasks * loh(n) push/pop = overall time complexity of this entire for loop
        return result;
    }
};