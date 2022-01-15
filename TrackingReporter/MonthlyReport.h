#pragma once
#include "EmployeeInfo.h"

class MonthlyReport
{
private:
	std::vector<EmployeeInfo> monthlyReportData;
	std::vector<std::string> separators = { ";", ":", "," };
	std::string separator;

	void InsertData(EmployeeInfo& employee, const std::vector<std::string>& data);
	OutputDate CorrectDate(std::string date);
public:
	MonthlyReport(std::string file);
	~MonthlyReport() {}

	void SortMonthlyReport(const std::string& field);
	void CreateOutputFile(const std::string& fileName);
};
