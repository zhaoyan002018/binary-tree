#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

void setFunc()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };

	multiset<int> s1(arr, arr + 10);//自动进行排序

	ostream_iterator<int> output(cout, " ");

	copy(s1.begin(), s1.end(), output);

	s1.insert(20);

	s1.insert(11);//自动排序
	copy(s1.begin(), s1.end(), output);

	multiset<int>::const_iterator ci;
	ci = s1.find(10);
	if (ci == s1.end())
	{
		cout << "未找到10" << endl;
	}
	else
	{
		cout << "找到了10" << endl;
		cout << *ci << endl;
	}

}

void mapFunc()
{
	string s[3] = { "beijing","shanghai","guangdong" };
	double sal[3] = { 1000,2000,3000 };
	map<string, double> m1;
	int i = 0;
	for (; i < 3; i++) m1[s[i]] = sal[i];

	map<string, double>::iterator it;
	for (it = m1.begin(); it != m1.end(); ++it)cout << it->first << ":" << it->second << '\t';
	cout << endl;
	//map<string, double>::value_type vt;
	m1.insert(map<string, double>::value_type("shanxi", 2000));
	for (it = m1.begin(); it != m1.end(); ++it)cout << it->first << ":" << it->second << '\t';

}

int main4()
{
	mapFunc();
	return 0;
}
