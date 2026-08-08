
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // rightMatch[i] stores the max length of word2's suffix matching word1[i...]
        vector<int> rightMatch(n + 1, 0);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            rightMatch[i] = rightMatch[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatch[i]++;
                j--;
            }
        }

        vector<int> seq;
        bool changePower = true;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            // Case 1: Exact character match
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } 
            // Case 2: Use wild-card change if allowed and remaining suffix matches
            else if (changePower && rightMatch[i + 1] >= m - j - 1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }
        }

        return (j == m) ? seq : vector<int>();
    }
};