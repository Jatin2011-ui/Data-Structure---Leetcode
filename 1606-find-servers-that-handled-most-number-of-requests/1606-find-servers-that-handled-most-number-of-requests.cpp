class Solution {
public:
    typedef pair<int, int> P; //{finishTime ,serrverId}
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0;i<k;i++){
            available_servers.insert(i); //k* log(k)
        }
        priority_queue<P, vector<P>, greater<P>> busyservers;
        vector<int> countrequests(k,0);
        //total requests - n;
        //T.C = n * log(k)
        for(int i=0;i<arrival.size();i++){
            int time = arrival[i];
            while(!busyservers.empty() && busyservers.top().first <= time){
                int server = busyservers.top().second;

                busyservers.pop();

                available_servers.insert(server);
            }
            int target  = i%k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()){//wrap around
                it = available_servers.begin();
            }
            if(available_servers.empty()){
                continue;//no servers available. drop the xurrent requests
            }
            int targetserver = *it;
            available_servers.erase(it);//bcoz this server is going to busy 
 
            busyservers.push({time + load[i], targetserver});

            countrequests[targetserver]++;
        }
        int maxnumberofrequests = *max_element(begin(countrequests), end(countrequests));//O(k)

        vector<int> result;

        for(int i=0;i<k;i++){
            if(countrequests[i] == maxnumberofrequests){
                result.push_back(i);
            }
        }
        return result;
    }
};