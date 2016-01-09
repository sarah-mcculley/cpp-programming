//
//  main.cpp
//  test 2
//
//  Created by Sarah McCulley on 11/29/15.
//  Copyright © 2015 Sarah McCulley. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Savings
{
    
    friend ostream& operator<<(ostream&, const Savings);
private:
    string _alias;
    double interest;
    double balance = 0.00;

    double calcInterest(double interest, double balance);
public:
    Savings(string, double);
    string alias(string);
    double deposit(double);
    
};

//implementation section
Savings::Savings(string alias, double interest)
{
    _alias = alias;
    this->interest=interest;
}

string Savings::alias(string alias)
{
    if (alias == "")
        cout << "You must give your savings account an alias.";
    else
        alias = alias;
    return alias;
}

double Savings::calcInterest(double interest, double balance)
{
    double newBalance = (interest * balance)+ balance;
    balance = newBalance;
    return balance;
}

double Savings::deposit(double deposit)
{;
    balance = balance + deposit;
    return calcInterest(interest, balance);
}

ostream& operator<< (ostream& out, const Savings savings)
{
    out << "The savings called " << savings._alias << " has " << savings.balance << endl;
    return out;
}

int main()
{
    Savings Larz("college", 0.05);
    Larz.alias("car");
    Larz.deposit(5000);
    cout << Larz << endl;

    return 0;
}

