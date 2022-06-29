#include "screenTest.h"
#include <stdexcept>
#include <fstream>
Screen& Screen::move(unsigned r,unsigned c)
{
    this->cursor = r * this->width + c;
    return *this;
}
Screen& Screen::set(char c)
{
    this->contents[this->cursor] = c;
    return *this;
}
Screen& Screen::set(unsigned r,unsigned c,char ch)
{
    this->contents[r * this->width + c] = ch;
    return *this; 
}
void Window::clear(ScreenIndex i)
{
    Screen &s =Screens[i];
    
    s.contents = string(s.height * s.width,' ');
}

istream& f(istream& in)
{
    int v;
    while (in >> v,!in.eof())
    {
        if (in.bad())
        {
            throw runtime_error("IO 流错误");
        }
        if (in.fail())
        {
            cerr << "数据错误,请重试: " << endl;
            in.clear();
            in.ignore(100,'\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;   
}
int main()
{
/*     Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n"; */
    ifstream in("../data.txt");
    if (!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    string line;
    vector<string> words;
    while (getline(in,line))
    {
        words.push_back(line);
    }
    in.close();
    vector<string>::const_iterator it;
    for(it = words.begin();it != words.end();++it)
    {
        cout << *it << endl;
    }
    
    

    return 0;
}