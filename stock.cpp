//
//  stock.cpp
//  stockCrawler
//
//  Created by Mohdi Habibi on 9/6/16.
//  Copyright © 2016 Mohdi Habibi. All rights reserved.
//

#include "stock.hpp"

stock::stock(string n, string d, double a){
    name = n;
    date = d;
    average = a;
}

void stock:: setDifference(double dif){
    difference = dif;
}

void stock:: setPercent(double per){
    percent = per;
}



void operator << (ostream &obj, const stock &right){
    obj << right.name << " " << right.date << " " << right.percent << endl;
}


