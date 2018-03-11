#include<stdio.h>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

string addint(string t1, string t2)
{
	string re="";
	int flag = 0;
	int i = t1.size() - 1;
	int j = t2.size() - 1;
	while (i >= 0 || j >= 0 || flag == 1)
	{
		flag += (i >= 0) ? (t1[i--] - '0') : 0;
		flag += (j >= 0) ? (t2[j--] - '0') : 0;
		re = char(flag % 2 + '0') + re;
		flag = flag / 2;
	}
	return re;
}

string int100(string& s)
{
	string re = "";
	unordered_map<int, string> list;
	list[0] = "0000";
	list[1] = "0001";
	list[2] = "0010";
	list[3] = "0011";
	list[4] = "0100";
	list[5] = "0101";
	list[6] = "0110";
	list[7] = "0111";
	list[8] = "1000";
	list[9] = "1001";
	for (int i = s.size() - 1; i >= 0; --i)
	{
		string thisNum = list[s[i]-'0'];
		for (int j = s.size()-1; j>i; --j)
		{
			thisNum = addint(thisNum + '0', thisNum + "000");
		}
		re = addint(re, thisNum);
	}
	return re;
}



void main()
{
	cout << "hello world!" << endl;
	string s1 = "29844574309275892037839743587348925438793094730957903274309257394207542309857438905";
	string re = int100(s1);
	//cout << addint("1010", "1110") << endl;   //二进制相加

	cout << re << endl;
	getchar();
}