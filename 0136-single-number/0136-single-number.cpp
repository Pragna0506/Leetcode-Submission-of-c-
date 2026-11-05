class Solution {
public:
    int singleNumber(vector<int>& nums) {
         unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }
        for (int num : nums) {
            if (hash[num] == 1)
                return num;
        }
        return -1;
        
    }
};