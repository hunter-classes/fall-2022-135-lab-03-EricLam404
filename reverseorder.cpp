// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

int days(int month){
    
    if(month == 2){
        return 28;
    }
    else if((month <= 7 && month % 2 == 1) || (month >= 8 && month <= 12 && month % 2 == 0)){
        return 31;
    }
    else {
        return 30;
    }
}
void reverse_order(std::string date1, std::string date2){
    int startMonth = std::stoi(date1.substr(0, 2));
    int startDay = std::stoi(date1.substr(3, 2));

    int endMonth = std::stoi(date2.substr(0, 2));
    int endDay = std::stoi(date2.substr(3, 2));

    int totalDays = 0;
    int count = 0;

    if(startMonth == endMonth){
        totalDays += endDay - startDay;
    }
    else{
        totalDays += days(startMonth) - startDay + 1;
        totalDays += endDay;
    }
    while((startMonth + count) != endMonth){
        if((startMonth + count != startMonth)){
            totalDays += days(startMonth + count);
        }
        count++;
    }

    std::string dates[totalDays];
    double datesEl[totalDays];

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    
    int getDate = false;
    int index = 0;

    std::string dateData;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> dateData >> eastSt >> eastEl >> westSt >> westEl) {     
        fin.ignore(INT_MAX, '\n'); 
        if(date1 == dateData){
            getDate = true;
        }
        if(index == totalDays){
            getDate = false;
        }
        if(getDate){
            dates[index] = dateData;
            datesEl[index] = westEl;
            index++;
        }
    }

    fin.close();

    for(int i = totalDays - 1; i >= 0; i--){
        std::cout << dates[i] << " " << datesEl[i] << " ft \n";
    }
}