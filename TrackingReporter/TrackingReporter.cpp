#include "MonthlyReport.h"
#include "Logger.h"

int main()
{
	std::string answer;
	std::string filename;
	std::string logger;

	while (true)
	{
		try
		{
			std::cout << "Do you want to measure the running time of each commands (yes/no): ";
			std::cin >> logger;
			if (logger == "yes")
			{
				std::string outputFile, inputFile, field;
				std::cout << "Enter input file, field for sorting, name for output file \n" <<
					"(For example inputFile hours outputFile) : ";
				std::cin >> inputFile >> field >> outputFile;

				{
					LOG_DURATION("Working with " + inputFile + ".csv file");
					MonthlyReport Report(inputFile);
					if (field != "none")
						Report.SortMonthlyReport(field);
					Report.CreateOutputFile(outputFile);
					Report.~MonthlyReport();
				}
			}
			else if (logger == "no")
			{
				std::cout << "Enter a file name or path (for example: csvData): ";
				std::cin >> filename;

				MonthlyReport Report(filename);

				while (true)
				{
					std::cout << "Enter the command (sort, output, stop): ";
					std::cin >> answer;

					if (answer == "sort")
					{
						std::cout << "Enter field for sorting: ";
						std::cin >> answer;
						Report.SortMonthlyReport(answer);
					}
					else if (answer == "output")
					{
						std::cout << "Enter a output file name (for example: csvData): ";
						std::cin >> filename;
						Report.CreateOutputFile(filename);
					}
					else if (answer == "stop")
					{
						Report.~MonthlyReport();
						break;
					}
				}
			}
			else throw std::exception("Wrong command");

			std::cout << "Do you want continue? (yes/no): ";
			std::cin >> answer;
			if (answer == "no") return 0;
			else if (answer == "yes") continue;
			else throw std::exception("Wrong command");
		}
		catch (std::exception ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}
