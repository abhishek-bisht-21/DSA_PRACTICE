#include <iostream>
#include <stack>
using namespace	std;


int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "Top Element: " << st.top() << endl;
	st.pop();
	cout << "Top Element: " << st.top() << endl;				
	st.push(8);
	st.push(5);
	cout << "Is Stack Empty: " << boolalpha << st.empty() << endl;
	return 0;
}