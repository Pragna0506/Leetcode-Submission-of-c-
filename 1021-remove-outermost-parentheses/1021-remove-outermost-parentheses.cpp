class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string result = "";
        int balance = 0;

        for (char ch : s) {
            
            if (ch == '(') {
                
                // Add '(' only if it is not the outermost
                if (balance > 0) {
                    result += ch;
                }
                
                balance++;
            }
            
            else {
                
                balance--;
                
                // Add ')' only if it is not the outermost
                if (balance > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};