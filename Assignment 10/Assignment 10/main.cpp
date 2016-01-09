//
//  main.cpp
//  Assignment 10
//
//  Created by Sarah McCulley on 11/30/15.
//  Copyright © 2015 Sarah McCulley. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Investment
{
protected:
    double investment;
    double currentValue;
    double profit;
    double percentProfit;
public:
    Investment(double, double);
    void InvestmentDisplay();
};

Investment::Investment(double investment, double currentValue)
{
    this->currentValue = currentValue;
    this->investment = investment;
    
    profit = currentValue - investment;
    percentProfit = (profit/investment) * 100;
}

void Investment::InvestmentDisplay()
{
   cout << "Investment current value $" << currentValue << endl
    << "Investment initial value $" << investment << endl
    << "Profit is $" << profit << " which is a " << percentProfit << "% profit" << endl;
}

class House
{
protected:
    string address;
    double sqFeet;
public:
    House(string, double);
    void HouseDisplay();
};

House::House(string address, double sqFeet)
{
    this->address = address;
    this->sqFeet = sqFeet;
}

void House::HouseDisplay()
{
    cout << "The house at " << address << " is " << sqFeet << " square feet" << endl;
}

class HTIAI : public Investment, public House
{
public:
    HTIAI(string, double, double, double);
    void DisplayHTIAI();
};

HTIAI::HTIAI(string address, double sqFeet, double investment, double currentValue)
: House(address, sqFeet), Investment(currentValue, investment)
{
    
}

void HTIAI::DisplayHTIAI()
{
    HouseDisplay();
    InvestmentDisplay();
}

int main()
{
    HTIAI htiai("12 Oak Street", 2000, 175000,140000);
    htiai.DisplayHTIAI();
    cout << endl << "Enter 'q' to quit:";
    cin.get();
    return 0;
}
