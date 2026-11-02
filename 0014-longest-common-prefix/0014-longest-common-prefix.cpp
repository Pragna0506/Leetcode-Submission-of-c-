class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x = 0;
      while (x < strs[0].length()) {
          char ch = strs[0][x];
          for (int i = 1; i < strs.size(); i++) {
              if (x == strs[i].length() || ch != strs[i][x]) {
                  return strs[0].substr(0, x);
              }
          }
          ++x;
      }
      return strs[0];
  }
};