#include <iostream>
#include <string>
using namespace std;

class Sales_item
{
public:
    Sales_item(const string &book):isbn(book),units_sold(0),revenue(0.0){}
    Sales_item(istream &is){is >> this->isbn >> this->units_sold >> this->revenue;}
    friend istream& operator >> (istream &,Sales_item &);
    friend ostream& operator << (ostream &,const Sales_item&);
    friend bool operator==(const Sales_item &lhs,const Sales_item &rhs);
    friend bool compareIsbn(const Sales_item &lhs,const Sales_item &rhs);
public:
    Sales_item & operator+=(const Sales_item&);
public:
    double avg_price()const;
bool same_isbn(const Sales_item &rhs)const
{
    return isbn == rhs.isbn;
}
Sales_item():units_sold(0),revenue(0.0){}
public:
    string isbn;
    size_t units_sold;
    double revenue;
};
Sales_item operator+(const Sales_item &,const Sales_item &);
inline bool operator==(const Sales_item &lhs,const Sales_item &rhs)
{
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.isbn == rhs.isbn;
}
inline bool operator!=(const Sales_item &lhs,const Sales_item &rhs)
{
    return !(lhs == rhs);
}
inline Sales_item &Sales_item::operator +=(const Sales_item &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}
inline Sales_item operator+(const Sales_item &lhs,const Sales_item &rhs)
{
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}
inline istream& operator>>(istream &in,Sales_item &s)
{
    double price;
    in >> s.isbn >> s.units_sold >> price;
    if (in)
    {
        s.revenue = s.units_sold *price;
    }
    else
    {
        s = Sales_item();
    }
    return in;
}
inline ostream& operator<<(ostream &out,const Sales_item &s)
{
    out << s.isbn << " t" << s.units_sold << "t" << s.revenue << "t" <<s.avg_price();
    return out;
}
inline double Sales_item::avg_price() const
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    return 0;
    
}

