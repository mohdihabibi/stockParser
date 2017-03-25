//
//  main.cpp
//  stockCrawler
//
//  Created by Mohdi Habibi on 9/6/16.
//  Copyright © 2016 Mohdi Habibi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stack>

#include "stock.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    stack <stock> stockStack;
    int index = 0;
    ifstream inFile;
    
    inFile.open("hourly_data.txt");
    if (!inFile.is_open()){
        cout << "The file is not open" << endl;
    }
    
    string tempDate, temp;
    double tempAverage, high, low, percent;
    
    stack<stock> positiveFlucStack;
    stack<stock> negativeFlucStack;
    
    while (!inFile.eof()){
        
        
        if (index == 0)
            getline(inFile,temp);
        
        inFile >> tempDate;
        inFile >> temp;
        inFile >> temp;
        inFile >> temp;
        inFile >> temp;
        
        inFile >> high;
        
        inFile >> low;
        tempAverage = (low+high)/2;
        getline(inFile,temp);
        stock tempStock("APPL",tempDate,tempAverage);
        
        if (index == 0){
            stockStack.push(tempStock);
            index++;
            continue;
        }
        
        double difference = stockStack.top().average - tempStock.average;
        tempStock.setDifference(difference);
        percent = (difference * 100)/stockStack.top().average;
        tempStock.setPercent(percent);
        
        
        
        if (difference < -1){
            positiveFlucStack.push(tempStock);
            stockStack.push(tempStock);
        }
        
        if (difference > 1){
            negativeFlucStack.push(tempStock);
            stockStack.push(tempStock);
        }
            
        index++;
        cout << index << endl;
    }
    
    inFile.close();
    
    cout <<"All fluctuations greater than $1 have been found and recorded."<< endl;
    
    ofstream outFile;
    outFile.open("outPut.txt");

    
    outFile << "name, Date, Average, Difference, Percentage\n" << endl;
    
    while(!positiveFlucStack.empty()){
        stock temp = positiveFlucStack.top();
        positiveFlucStack.pop();
        outFile << temp;
        
    }
    
    while(!negativeFlucStack.empty()){
        
        stock temp = negativeFlucStack.top();
        negativeFlucStack.pop();
        outFile << temp;
        
    }
    
    cout <<"All have been saved to a file." << endl;
    
    return 0;
}
