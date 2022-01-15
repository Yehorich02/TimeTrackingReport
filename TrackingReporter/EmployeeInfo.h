#pragma once 
#include <string>
#include <fstream>
#include<iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <utility>

struct OutputDate
{
	uint32_t month;
	uint32_t year;
};
struct EmployeeInfo
{
	std::string fullName;
	std::string email;
	std::string department;
	std::string position;
	std::string project;
	OutputDate date;
	uint32_t hours;
};

static std::vector< uint16_t> months = { 31,28,31,30,31,30,31,31,30,31,30,31 };

static std::vector< std::string> namesOfMonths = { "January", "February", "March",
"April", "May", "June", "July", "August", "September","October", "November",
"December" };

static bool operator == (const EmployeeInfo& first, const EmployeeInfo& second)
{
	if (first.fullName == second.fullName
		&& first.email == second.email
		&& first.department == second.department
		&& first.position == second.position
		&& first.project == second.project
		&& first.date.month == second.date.month
		&& first.date.year == second.date.year)
		return true;
	else
		return false;
}

inline bool operator < (const OutputDate& first, const OutputDate& second)
{
	if (first.year < second.year) return first.year < second.year;
	else if (first.year == second.year) return first.month < second.month;
	else return first.year < second.year;
}

static std::ostream& operator<< (std::ostream& out, const OutputDate& date)
{
	out << namesOfMonths[date.month - 1] << " " << date.year;
	return out;
}