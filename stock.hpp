//
//  stock.hpp
//  stockCrawler
//
//  Created by Mohdi Habibi on 9/6/16.
//  Copyright © 2016 Mohdi Habibi. All rights reserved.
//

#ifndef stock_hpp
#define stock_hpp


#include <stdio.h>
#include <iostream>

using namespace std;

class stock{
    friend void operator << (ostream&, const stock &);
    
public:
    
    string name;
    string date;
    double average;
    double difference = 0.0;
    double percent = 0.0;
    
    void setDifference (double);
    void setPercent(double);
    
    stock (string, string, double);
    
};
#endif /* stock_hpp */
