#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 0;

	while (N--)
	{
		string s;
		cin >> s;

		vector<char> st;
		st.reserve(s.size());

		for (char c : s)
		{
			if (!st.empty() && st.back() == c) 
			{
				st.pop_back();
			}
			else
			{
				st.push_back(c);
			}
		}

		if (st.empty()) answer++;
	}

	cout << answer << '\n';
	return 0;
}