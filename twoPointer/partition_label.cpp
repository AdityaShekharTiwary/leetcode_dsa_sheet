class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> lastPos(26, 0);
        for (int i = 0; i < s.size(); i++) lastPos[s[i] - 'a'] = i;
        int partitionLenght = 0, lastOccurance = -1;
        for (int i = 0; i < s.size(); i++) {
            int curr = lastPos[s[i] - 'a'];
            lastOccurance = max(lastOccurance, curr);
            partitionLenght++;
            if (lastOccurance == i) {
                ans.push_back(partitionLenght);
                partitionLenght = 0;
                lastOccurance = -1;
            }
        }
        return ans;
    }
};