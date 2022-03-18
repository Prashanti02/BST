//
//  Stock.cpp
//  BST
//
//  Created by Prashanti Pokharel on 10/11/21.
//


#include "Stock.h"
#include <iostream>
#include <string>

using namespace std;

Stock::Stock(const string& name, const string& symbol, double price)
{
    this->name = name;
    this->symbol = symbol;
    this->price = price;
}

Stock::Stock(const Stock& s)
{
    this->name = s.name;
    this->symbol = s.symbol;
    this->price = s.price;
}

void Stock::display() const
{
    cout << "Name is " << name << ", "
        << "Symbol is " << symbol << ", "
        << "Price is " << price << ".\n";
}
std::ostream& operator<< (ostream& out, const Stock& s)
{
    out << "Stock name: " << s.name << std::endl
        << "Stock symbol: " << s.symbol << std::endl
        << "Stock price: " << s.price << std::endl;
    return out;
}
