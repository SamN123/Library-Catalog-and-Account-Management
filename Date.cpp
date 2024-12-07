#include<string>
#include "string.h"
#include<sstream>

using namespace std;

class Date{
    string date;
    int year = 0;
    int month = 0;
    int day = 0;
    
    public:
    Date() {

    }
    Date(string input) {
        year = stoi(input.substr(0,4));
        month = stoi(input.substr(4,2));
        day = stoi(input.substr(6,2));
    }

    Date(int input) {
        date = to_string(input);
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(4,2));
        day = stoi(date.substr(6,2));
    }

    void setDate(int input) {
        string temp = to_string(input);
        year = stoi(temp.substr(0,4));
        month = stoi(temp.substr(4,2));
        day = stoi(temp.substr(6,2));
    };

    void setDate(string input) {
        year = stoi(input.substr(0,4));
        month = stoi(input.substr(4,2));
        day = stoi(input.substr(6,2));
    };

    int newDate(int input) {
        day = day + input;
        bool noChange;
        while(!noChange) {
            noChange = true;
            switch(month) {
                case 1: if(day > 31) {
                    month++;
                    day -= 31;
                    noChange = false;
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
            if(month > 12) {
                year++;
                month -= 12;
                noChange = false;
            }
        };

        string output = to_string(year);
        if (month < 10) output = output + "0";
        output = output + to_string(month);
        if (day < 10) output = output + "0";
        output = output + to_string(day);

        return stoi(output);
    }
};
