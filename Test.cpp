#include"MyString.h"
#include<string>
int main()
{
	MyString a;
	getline(cin, a);
	cout << a << endl;
	cin >> a;
	cout << a << endl;

	return 0;
}
