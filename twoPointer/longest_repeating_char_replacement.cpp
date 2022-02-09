class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0, start = 0, end = 0, currMax = 0;
        unordered_map<char, int> hash;
        while (end < n) {
            // populating the hashmap
            hash[s[end]]++;
            int currFreq = hash[s[end]];
            // getting the current maximum frequency of the window
            currMax = max(currMax, currFreq);
            //out of operations :-- remove from start
            while (end - start + 1 - currMax > k) {
                hash[s[start]]--;
                start++;
            }
            // storing max length of the window
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
};