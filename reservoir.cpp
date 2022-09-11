// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateData;
    double eastSt;

    while(fin >> dateData >> eastSt) {     
        fin.ignore(INT_MAX, '\n'); 
        if(dateData == date){
            return eastSt;
        }
    }
    fin.close();
    return 0;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateData;
    double eastSt;
    double min = INT_MAX;

    while(fin >> dateData >> eastSt) {     
        fin.ignore(INT_MAX, '\n'); 
        if(eastSt < min){
            min = eastSt;
        }
    }

    fin.close();
    return min;
}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateData;
    double eastSt;
    double max = INT_MIN;

    while(fin >> dateData >> eastSt) {     
        fin.ignore(INT_MAX, '\n'); 
        if(eastSt > max){
            max = eastSt;
        }
    }

    fin.close();
    return max;
}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateData;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> dateData >> eastSt >> eastEl >> westSt >> westEl) {     
        fin.ignore(INT_MAX, '\n'); 

        if(dateData == date){
            return eastEl > westEl ? "East" : eastEl < westEl ? "West" : "Equal";
        }
    }
    fin.close();
    return "";
}