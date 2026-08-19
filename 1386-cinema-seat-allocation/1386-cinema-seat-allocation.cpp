//Approach-1 (Greedy Pick using map)
//T.C : O(N), N = reservedSeats.size()
//S.C : O(N), for storing reswerved seats in map (in form of unordered_set)

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp; //row -> seats in each row booked

        for(auto& reservedSeat: reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }
        int result = (n - mp.size()) * 2;

        for(auto& [row, bookedSeats] : mp){
        auto isAvaiable = [&](int seat){
            return bookedSeats.find(seat) == bookedSeats.end();
        };

        bool groupA = isAvaiable(2) && isAvaiable(3) && isAvaiable(4) && isAvaiable(5);
        bool groupB = isAvaiable(4) && isAvaiable(5) && isAvaiable(6) && isAvaiable(7);
        bool groupC = isAvaiable(6) && isAvaiable(7) && isAvaiable(8) && isAvaiable(9);

        if(groupA && groupC)
            result += 2;
        else if(groupA | groupB | groupC)
            result += 1;
        }

    return result;
    }
};