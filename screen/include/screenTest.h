#include <iostream>

#include <vector>
using namespace std;

class Window;
class Screen
{
friend Window;
private:
    unsigned height = 0,width = 0;
    unsigned cursor = 0;
    string contents = 0;
    void do_display(ostream& os) const{os << contents;}
public:
    Screen(/* args */) = default;
    Screen(unsigned ht,unsigned wd):height(ht),width(wd),
    contents(ht * wd,' '){}
    Screen(unsigned ht,unsigned wd,char s):height(ht),width(wd),
    contents(ht * wd,s){}
public:
    Screen& move(unsigned r,unsigned c);
    Screen& set(char ch);
    Screen& set(unsigned r,unsigned c, char ch);
    Screen& display(ostream &os)
    {do_display(os);return *this;}
    const Screen display(ostream &os) const
    {do_display(os);return *this;}
};
class Window
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex i);
private:
    vector<Screen> Screens{Screen(24,80,' ')};
};
