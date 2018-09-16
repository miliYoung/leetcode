/**
 * LEETCODE 678. Valid Parenthesis String
 */

/**
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
 *  We define the validity of a string by these rules:
 *  Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 *  Any right parenthesis ')' must have a corresponding left parenthesis '('.
 *  Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 *  '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 *  An empty string is also valid.
 *  Example 1:
 *  Input: "()"
 *  Output: True
 *  Example 2:
 *  Input: "(*)"
 *  Output: True
 *  Example 3:
 *  Input: "(*))"
 *  Output: True
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1;
		stack<int> st2;
        
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);
			if (c == '(')
				st1.push(i);
			else if (c == '*')
				st2.push(i);
			else {
				if (!st1.empty())
					st1.pop();
				else if (!st2.empty())
					st2.pop();
				else 
					return false;
			}
		}
        
		while (!st1.empty()) {
			int n1 = st1.top();
            st1.pop();
			if (st2.empty())
				return false;
			int n2 = st2.top();
            st2.pop();
			if (n1 > n2)
				return false;
		}
		return true;
    }
};