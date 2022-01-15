# Time tricking report

## Requirements
It is needed to create a console C++ application which would take time report of all employees and generate monthly report.

## Functionality
* User can measure the running time of the program.
* To start the program, user must enter the name of the input file (For example *inputFile**, without **.csv**).
* Using the ***sort field*** command, you can sort the source file by a specific criterion.
* To write data to the source file, use the ***output*** command and then type the name of the source file (For example *outputFile*, without ***.csv***). After this command, the user can continue working with the input file and create new(another) source file.
* To stop working with the input file, user must enter the ***stop*** command.
* After the ***stop*** command, user can continue working with another input file or quit the program.

## Manual
 If the user answered to this quation **yes**:
```
 Do you want to measure the running time of each commands (yes/no): 
```
You need to enter the query in the following form of ***input file***,  ***type of field to sort*** (if you don`t need to sort, enter **none**), ***output file***. (Without commas)

For example:
```
Enter input file, field for sorting, name for output file
(For example inputFile hours outputFile) : janData hours janReport
```

 If the user answered **no**:
 The program will ask the user to enter the name of the ***input file*** to start working with it. The file name must be entered **without .csv**.
After that you can choose one of the three commands (sort, output, stop) to work with file.
