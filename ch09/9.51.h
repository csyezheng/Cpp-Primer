#ifndef SKFLS_H
#define SKFLS_H

#include <string>

class Date
{
public:
	Date(const std::string &date)
	{
		if (date.find_first_of(',') != std::string::npos)
		{
			auto i = date.find_first_of(" ");
			auto j = date.find_first_of(',');
			day = stoi(date.substr(i + 1, j - i - 1));
			year = stoi(date.substr(j + 1, date.size() - j - 1));
		}
		else if (date.find_first_of("/") != std::string::npos)
		{
			auto i = date.find_first_of("/");
			auto j = date.find_last_of("/");
			day = stoi(date.substr(i + 1, j - i - 1));
			year = stoi(date.substr(j + 1, date.size() - j - 1));
		}
		else
		{
			auto i = date.find_first_of(" ");
			auto j = date.find_last_of(" ");
			day = stoi(date.substr(i + 1, j - i - 1));
			year = stoi(date.substr(j + 1, date.size() - j - 1));
		}
		if (date.find("Jan") < date.size())  month = 1;
		if (date.find("Feb") < date.size())  month = 2;
		if (date.find("Mar") < date.size())  month = 3;
		if (date.find("Apr") < date.size())  month = 4;
		if (date.find("May") < date.size())  month = 5;
		if (date.find("Jun") < date.size())  month = 6;
		if (date.find("Jul") < date.size())  month = 7;
		if (date.find("Aug") < date.size())  month = 8;
		if (date.find("Sep") < date.size())  month = 9;
		if (date.find("Oct") < date.size())  month = 10;
		if (date.find("Nov") < date.size())  month = 11;
		if (date.find("Dec") < date.size())  month = 12;
	}
private:
	unsigned year;
	unsigned month;
	unsigned day;
};

#endif