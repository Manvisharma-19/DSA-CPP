class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // 1. Check for opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // 2. Check for closing brackets
            else {
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                // Check all matching pairs
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // 3. If stack is empty, all brackets matched successfully
        return st.empty();
    }
};
