//
//  Stock.h
//  BST
//
//  Created by Prashanti Pokharel on 10/11/21.
//

#ifndef Stock_h
#define Stock_h

#include <iostream>
#include <string>

class Stock
{
private:
    std::string name;
    std::string symbol;
    double price;
public:
    Stock(const std::string& name=" " , const std::string& symbol="", double price=0);
    Stock(const Stock& s);
    void display () const;
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;
    bool operator==(const Stock& rhs) const;
    bool operator!=(const Stock& rhs) const;
    bool operator>(const Stock& rhs) const;
    bool operator<(const Stock& rhs) const;
    friend std::ostream& operator << (std::ostream & out, const Stock& s);
};

    inline
    std::string Stock::getName() const
    {
        return name;
    }
    inline
    std::string Stock:: getSymbol() const{
    return symbol;
    }
    inline
    double Stock::getPrice() const
    {
        return price;
    }
inline
bool Stock::operator==(const Stock& rhs) const
{
    return (symbol == rhs.symbol);
}

inline
bool Stock::operator!=(const Stock& rhs) const
{
    return (symbol != rhs.symbol);

}

inline
bool Stock::operator>(const Stock& rhs) const
{
    return (symbol > rhs.symbol);
}

inline
bool Stock::operator<(const Stock& rhs) const
{
    return (symbol < rhs.symbol);
}
 
#endif /* Stock_h */
