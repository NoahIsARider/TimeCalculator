/*
 * This C++ program is designed to calculate the difference in seconds between two date - time points entered by the user.
 *
 * Usage Instructions:
 *
 * 1. Compilation:
 *    - Save the code in a file with a .cpp extension, for example, "date_time_diff.cpp".
 *    - Open a terminal or command prompt. Navigate to the directory where the file is saved.
 *    - Use a C++ compiler to compile the code. For example, with g++:
 *      g++ date_time_diff.cpp -o date_time_diff
 *
 * 2. Execution:
 *    - After successful compilation, run the executable. In the terminal, type:
 *      ./date_time_diff
 *
 * 3. Input Format:
 *    - The program will prompt you to enter two date - time values.
 *    - Each date - time value should be entered in the format: yyyy,m,d,h,min,s.
 *    - For example: 2024,2,23,10,30,30
 *    - The first input will represent the first date - time point, and the second input will represent the second date - time point.
 *
 * 4. Output:
 *    - After entering both date - time values, the program will calculate and display the difference in seconds between the two date - time points.
 *    - The output will be in the form of "Difference in seconds: [number of seconds]".
 *
 * Class Descriptions:
 *
 * Time Class:
 *    - Represents a time point with hours, minutes, and seconds.
 *    - Provides methods to set and get hours, minutes, and seconds.
 *    - Can add seconds, minutes, and hours to the current time, handling overflows and underflows correctly.
 *    - The toSeconds() method converts the time to seconds.
 *
 * Date Class:
 *    - Represents a date with year, month, and day.
 *    - Can find the maximum number of days in the current month, taking leap years into account.
 *    - Provides methods to add days and months to the current date, handling month and year transitions correctly.
 *    - The isLeapYear() method checks if the current year is a leap year.
 *    - The toDays() method calculates the number of days from January 1st, year 1 to the current date.
 *
 * DateTime Class:
 *    - Inherits from both Date and Time classes.
 *    - Represents a complete date - time point.
 *    - The diffSeconds() method calculates the difference in seconds between two DateTime objects.
 *
 * Main Function:
 *    - Reads two date - time values from the user.
 *    - Parses the input values to create two DateTime objects.
 *    - Calls the diffSeconds() method to calculate the difference in seconds between the two DateTime objects.
 *    - Outputs the result to the console.
 */


#include <iostream>
#include <sstream>
#include <string>
#include "DateTime.h"
using namespace std;
int main() {
    string input1, input2;
    int year1, month1, day1, hour1, minute1, second1;
    int year2, month2, day2, hour2, minute2, second2;

    // 提示用户输入第一个日期时间
    getline(cin, input1);
    stringstream ss1(input1);
    char comma;
    ss1 >> year1 >> comma >> month1 >> comma >> day1 >> comma >> hour1 >> comma >> minute1 >> comma >> second1;

    // 提示用户输入第二个日期时间
    getline(cin, input2);
    stringstream ss2(input2);
    ss2 >> year2 >> comma >> month2 >> comma >> day2 >> comma >> hour2 >> comma >> minute2 >> comma >> second2;

    // 创建DateTime对象
    DateTime dt1(year1, month1, day1, hour1, minute1, second1);
    DateTime dt2(year2, month2, day2, hour2, minute2, second2);

    // 计算并输出两个日期时间之间相差的秒数
    cout << "Difference in seconds: " << dt2.diffSeconds(dt1) << endl;

    return 0;
}