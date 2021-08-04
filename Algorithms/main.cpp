#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>
#include <time.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& ostr, const vector<T> & v)
{
	for (const auto& val : v)
		ostr << val << ' ';
	if (v.empty())
		ostr << "[empty vector]";
	ostr << '\n';
	return ostr;
}

int main()
{
	srand(unsigned(time(NULL)));
	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	cout << v;
	cout << boolalpha;
	cout << all_of(v.cbegin(), v.cend(), [](auto i) { return i < 20; }) << '\n';
	cout << all_of(v.cbegin(), v.cend(), [](auto i) { return i != 3; }) << '\n';
	cout << any_of(v.cbegin(), v.cend(), [](auto i) { return i != 3; }) << '\n';
	vector<vector<int>> mat(10, vector<int>(10));
	int i = 0;
	for_each(mat.begin(), mat.end(), [&i](auto& row)
	{
		iota(row.begin(), row.end(), rand() % 10);
		++i;
	});
	cout << mat << '\n';
}