class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            // Closing bracket
            else {

                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                // Check matching brackets
                if (ch == ')' && top != '(') {
                    return false;
                }

                if (ch == ']' && top != '[') {
                    return false;
                }

                if (ch == '}' && top != '{') {
                    return false;
                }
            }
        }

        // Stack must be empty
        return st.empty();
    }
};