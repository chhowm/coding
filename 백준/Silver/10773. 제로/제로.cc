#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, sum=0;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0) st.pop();
		else
		{
			st.push(temp);
		}
	}
	while (!st.empty())
	{
		sum = sum + st.top();
		st.pop();
	}
	cout << sum << endl;
	return 0;
}