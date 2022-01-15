#include "MonthlyReport.h"


#define Sort(field, arr)  std::sort(arr.begin(), arr.end(), \
						  [](EmployeeInfo first, EmployeeInfo second) \
						  {return first.field < second.field; });

void MonthlyReport::InsertData(EmployeeInfo& employee, const std::vector<std::string>& data)
{
	employee.fullName = data[0];
	employee.email = data[1];
	employee.department = data[2];
	employee.position = data[3];
	employee.project = data[4];
	employee.date = CorrectDate(data[6]);
	employee.hours = std::stoi(data[7]);
}

OutputDate MonthlyReport::CorrectDate(std::string date)
{
	uint16_t month;
	uint32_t year;
	uint16_t day;
	year = std::stoi(date);
	date.erase(date.begin(), date.begin() + date.find_first_of('-') + 1);
	month = std::stoi(date);
	date.erase(date.begin(), date.begin() + date.find_first_of('-') + 1);
	day = std::stoi(date);
	if (month > 12 || day > months[month - 1]
		|| (year % 4 == 0 && month == 2 && day > 28))
		throw std::exception("Incorrect date");
	return { month, year };
}

MonthlyReport::MonthlyReport(std::string file)
{
	std::fstream inputFile(file + ".csv", std::ios::in);
	std::string line;
	std::string word;
	if (!inputFile.is_open())
	{
		throw std::exception("Could not open file");
	}
	else
	{
		std::vector<std::string> tmp;
		std::getline(inputFile, line);
		for (const auto a : separators)
		{
			if (line.find(a))
			{
				separator = a;
				break;
			}
		}

		if (separator.empty())
		{
			throw std::exception("Separator do not find");
		}

		while (std::getline(inputFile, line))
		{
			EmployeeInfo employee;
			std::stringstream ss(line);
			tmp.clear();

			while (std::getline(ss, word, separator[0]))
			{
				tmp.push_back(word);
			}

			InsertData(employee, tmp);
			auto position = std::find_if(monthlyReportData.begin(), monthlyReportData.end(),
				[employee](EmployeeInfo val) {return employee == val; });
			if (position != monthlyReportData.end())
			{
				monthlyReportData[position - monthlyReportData.begin()].hours += employee.hours;
			}
			else
			{
				monthlyReportData.push_back(employee);
			}
		}
		inputFile.close();
	}
}


void MonthlyReport::SortMonthlyReport(const std::string& field)
{
	if (field == "fullName") { Sort(fullName, monthlyReportData); }
	else if (field == "email") { Sort(email, monthlyReportData); }
	else if (field == "department") { Sort(department, monthlyReportData); }
	else if (field == "position") { Sort(position, monthlyReportData); }
	else if (field == "project") { Sort(project, monthlyReportData); }
	else if (field == "date") { Sort(date, monthlyReportData); }
	else if (field == "hours") { Sort(hours, monthlyReportData); }
	else
	{
		throw std::exception("Incorect sort criterion");
	}
}

void MonthlyReport::CreateOutputFile(const std::string& fileName)
{
	std::ofstream outputFile(fileName + ".csv");

	outputFile << "Name" << separator << "Month" << separator << "Total hours" << "\n";

	for (const auto param : monthlyReportData)
	{
		outputFile << param.fullName << separator << param.date << separator
			<< param.hours << "\n";
	}

	outputFile.close();
	std::cout << "File " + fileName + ".csv created" << std::endl;
}