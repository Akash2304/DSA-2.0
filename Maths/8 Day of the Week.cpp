/*************************************************************************************************************************************************************************
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
****************************************************************************************************************************************************************************/
class Solution {
public:
    int daysOfMonth[2][12] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    string weekName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    bool isleapyear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    int daystill1971(int year, int month, int day)
    {
        int count = 0;
        int year1 = 1970, month1 = 1, day1 = 1;
        while (year1 != year)
        {
            bool b = isleapyear(year1);
            if (b) count += 366;
            else count += 365;
            year1++;
        }
        int b = isleapyear(year1) ? 0 : 1;
        for (int i = 0; i < month - 1; i++) count += daysOfMonth[b][i];
        count += day - 1;
        return count;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int days1 = daystill1971(2000, 4, 23);//today(2000,4,23) is Sunday
         
        
//So, days2 holds the total number of days from January 1, 1970, to the input date, and this value is used later in the calculation to
      // determine the day of the week for that date.     
        int days2 = daystill1971(year, month, day);
        int days = (((days2 - days1) % 7) + 7) % 7;//Number of days off
        return weekName[days];
    }
};

// why we evaluate this  int days1 = daystill1971(2019, 9, 8);
ChatGPT
The line int days1 = daystill1971(2000, 4, 23); is used to determine a reference point for the calculation of the day of the week. In this code, 
  the reference date chosen is April 23, 2000, which is known to be a Sunday. The purpose of this reference point is to calculate the number of days
between this known Sunday and the input date, and then determine the day of the week for the input date.  we can take any date as refrence if it is to be sunday only

Here's why this reference point is used:

September 8, 2019, is a known Sunday. This means that it's a convenient starting point because you can directly set it as a reference date with a known day of the week.

By calculating the number of days between this reference date (September 8, 2019) and the input date using the daystill1971 function, 
you're finding out how many days have passed since the reference date.

Once you have the number of days that have passed since the reference date, you can calculate the day of the week for the input date by
taking the difference between the calculated days and the known reference point (September 8, 2019) and finding the remainder when divided by 7. 
This will give you the number of days offset from Sunday.

Using the calculated offset, you can then retrieve the corresponding day name from the weekName array.

In essence, this process allows you to determine the day of the week for any given date by leveraging the known day of the week for September 8, 2019.
  The reference date helps anchor the calculation and provides a consistent way to determine the day of the week for any date.//

