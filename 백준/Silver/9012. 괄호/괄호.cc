#include <iostream>
#include <string>
#include <stack>
using namespace std;

int CheckVPS(const string s)
{
	stack<char> st;
	for (char c : s)
	{
		if (c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			if (st.empty() || st.top() != '(') return 0;
			st.pop();
		}
	}
	if (st.empty()) return 1;
	else return 0;
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++)
	{
		string s;
		getline(cin, s);
		if (CheckVPS(s)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}