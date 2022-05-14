// CamelCase4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <iterator>
#include <functional>
#include <string_view>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

int main() {

	string s;

	while (getline(cin, s))
	{
		s = ltrim(rtrim(s));

		char sc = s[0];

		if (sc == 'S')
		{
			char mvc = s[2];

			string ss = s.substr(4);

			string retValue;

			for (int i = 0; i < ss.length(); i++)
			{
				char letter = ss[i];

				if (letter >= 'A' && letter <= 'Z')
				{
					if (i == 0)
						retValue.push_back(tolower(letter));
					else
					{
						retValue.push_back(' ');
						retValue.push_back(tolower(letter));
					}
						
				}

				else retValue += letter;
			}

			if (mvc == 'M')
				retValue = retValue.substr(0, retValue.size() - 2);

			cout << retValue << endl;
		}
		else
		{
			char mvc = s[2];

			string ss = s.substr(4);

			string retValue;

			char prev;

			for (int i = 0; i < ss.length(); i++)
			{
				char letter = ss[i];

				if (i == 0)
				{
					if (mvc == 'C')
						retValue.push_back(toupper(letter));
					else
						retValue.push_back(letter);

					prev = letter;
				}
				else
				{
					if (letter != ' ')
					{
						if (prev == ' ')
						{
							retValue.push_back(toupper(letter));
						}
						else
							retValue.push_back(letter);
					}
					
					prev = letter;
				}
			}

			if (mvc == 'M')
				retValue += "()";

			cout << retValue << endl;
		}
	}

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}