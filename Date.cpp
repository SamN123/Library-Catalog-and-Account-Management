#include<string>
#include "string.h"

using namespace std;

class Date{ //class used to store and manipulate the due dates of books
    string date;
    int year = 0;
    int month = 0;
    int day = 0;
    
    public:
    Date() {

    }
    Date(string input) { //constructor if passed a date as a string
        year = stoi(input.substr(0,4));
        month = stoi(input.substr(4,2));
        day = stoi(input.substr(6,2));
    }

    Date(int input) { //constructor if passed a date as an integer
        date = to_string(input);
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(4,2));
        day = stoi(date.substr(6,2));
    }

    void setDate(int input) { //sets the current date with an integer input
        string temp = to_string(input);
        year = stoi(temp.substr(0,4));
        month = stoi(temp.substr(4,2));
        day = stoi(temp.substr(6,2));
    };

    void setDate(string input) { //sets the current date with a string as input
        year = stoi(input.substr(0,4));
        month = stoi(input.substr(4,2));
        day = stoi(input.substr(6,2));
    };

    int newDate(int input) { //generates a new due date based on the current date and an integer numter of days
        day = day + input;    //adds input number of days to the current day value
        bool noChange;    //flag to check if there was a change in date while finding the new day
        while(!noChange) { //iterative calculation adds 1 to month if the days value is larger than the corresponding month
            noChange = true; //reset the flag each loop cycle
            switch(month) { //switch to the current month value
                case 1: if(day > 31) {
                    month++; //add 1 to the month value
                    day -= 31; //reduce number of days by equivalent day value per month
                    noChange = false; //set the no change flag to false, continuing the loop
                }
                break;
                case 2: if(day > 29 && year%4 == 4){
                    month++;
                    day -= 29;
                    noChange = false;
                }
                if(day > 28){
                    month++;
                    day -= 28;
                    noChange = false;
                }
                break;
                case 3: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;
                case 4: if(day > 30){
                    month++;
                    day -= 30;
                    noChange = false;
                }
                break;
                case 5: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;
                case 6: if(day > 30){
                    month++;
                    day -= 30;
                    noChange = false;
                }
                break;
                case 7: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;
                case 8: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;
                case 9: if(day > 30){
                    month++;
                    day -= 30;
                    noChange = false;
                }
                break;
                case 10: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;
                case 11: if(day > 30){
                    month++;
                    day -= 30;
                    noChange = false;
                }
                break;
                case 12: if(day > 31){
                    month++;
                    day -= 31;
                    noChange = false;
                }
                break;

            }
            if(month > 12) { //increments the year value if months is greater than 12
                year++;
                month -= 12;
                noChange = false;
            }
        };

        //converts and concatenates the date values to a string and adds leading zeros when necissary
        string output = to_string(year); 
        if (month < 10) output = output + "0";
        output = output + to_string(month);
        if (day < 10) output = output + "0";
        output = output + to_string(day);
        //returns the new due date
        return stoi(output);
    }
};
