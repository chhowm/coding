#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	
	while (1)
	{
		getline(cin, s);
		if (s == ".") break;
		
		stack<char> st;
		bool ok = true;
		for (char c : s)
		{
			if (c == '(' || c == '[')
			{
				st.push(c);
			}
			else if (c == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					ok = false;
					break;
				}
				st.pop();
			}
			else if (c == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					ok = false;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty()) ok = false;

		cout << (ok ? "yes\n" : "no\n");
	}
	
	return 0;
}