class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp; //row - > seats in each row booked
        for(auto& reservedSeat : reservedSeats){//O(10^4)
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row] |= (1 << seat); // sets bits are booked seats
        }
        int result = ( n - mp.size()) * 2;
        int maskA = (1 << 2) | ( 1 << 3) | (1 << 4) | (1 << 5);//set bits are the ones which I need empty for Group A
        int maskB = (1 << 4) | ( 1 << 5) | (1 << 6) | (1 << 7);//set bits are the ones which I need empty for Group B
        int maskC = (1 << 6) | ( 1 << 7) | (1 << 8) | (1 << 9);//set bits are the ones which I need empty for Group C

        for(auto& [row, bookedSeatMask] : mp){//min(10*n, 10^4)
            bool groupA = (bookedSeatMask & maskA) == 0;
            bool groupB = (bookedSeatMask & maskB) == 0;
            bool groupC = (bookedSeatMask & maskC) == 0;

            if(groupA && groupC)
                result += 2;
            else if(groupA || groupB || groupC)
                result += 1;
        }
        return result;
    }
};