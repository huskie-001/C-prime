#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//#include <opencv2/opencv.hpp>
#include <unordered_map>
#include<string>
#include "test.h"
using namespace std;

void exchange(int *a,int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

int find_char(const string &s,char c,int &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
            {
                cout << "s.size = " << ret << endl;;
                ret = i;
            }
            ++occurs;
            
        }

        
    }
    return ret;
     
}
void isup(const string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]))
        {
            cout << "含有大写" << endl;
            break;
            
        }
        else if(i == s.size() - 1)
        {
            cout << "不含有大写" << endl; 
        }
        
    }
    
}
void changeTolower(string &s)
{
    for (auto &c:s)
    {
        c = tolower(c); 
    }
    cout << s << endl;
}
void print(const vector<int>&a,int index)
{
    if (!a.empty() && index != a.size())
    {
        cout << a[index] << endl;
        print(a,index+1);

    }
    
}
int func1(int a,int b)
{
    return a + b;
}

int func2(int a,int b)
{
    return a *b;
}
void Compute(int a,int b,int(*p)(int,int))
{
    cout << p(a,b) << endl;
}

inline
istream& Person::read(istream &is,Person &Per)
{
    is >> Per.strName>> Per.strAddress;
    return is;
}

inline
ostream& Person::print(ostream &os,const Person &Per)
{
    os << Per.getName() << Per.getAddress() << endl;
    return os;
}

Person::Person(const string &name,const string &add)
{
    this->strName = name;
    this->strAddress = add;
}
Person::Person(std::istream &is)
{
    is >> this->strName >> this->strAddress;
}
int main()
{
/*         string word;
        vector<string> text;
        
        while (cin >> word)
        {
            if (word == "q")
            {
                break; 

            }
            text.push_back(word);
            
        }
        for(auto i : text)
        {
            cout << i << endl;
        }
        if (!text.empty())
        {   
            int i = 0;
            int j = 0;
            while (i < text.size())
            {   
                for (auto &a:text[i])
                {
                    a = toupper(a);
                }
                i++;
                
            }
            
        }
        for (auto i:text)
        {
            cout << i << endl;
    }
     */

/*     vector<int>a,b;
    for(int i =0;i<10;i++)
    {
        a.push_back( rand()%10);
    }

        for(int i =0;i<10;i++)
    {
        b.push_back( rand()%10);
    }
    auto it1 = a.cbegin();auto it2 = b.cbegin();
    while (it1 != a.cend() && it2 !=b.cend())
    {
        if (*it1 != *it2)
        {
            cout << "两个数组不相等" << endl;
            return -1;
        }
        it1++;
        it2++;
    }
    cout << "相等" << endl;
 */
/*     const char ca[] = {'h','e','l','l','o'};
    const char *cp = ca;
    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
    
    return 0; */
/*     vector<int> vInt;
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        vInt.push_back(rand()%100);
    }
    auto it = vInt.cbegin();
    for (auto &val:a)
    {
        val = *it;
        it++;
        cout << val << endl;
    } */
/*     int a =6;
    int *p = &a;
    cout << "bool\t\t" << sizeof(bool) << endl;
    cout << "char\t\t" << sizeof(char) << endl;
    cout << "*p\t\t" << sizeof(p) << endl;
    cout << "int\t\t" << sizeof(int) << endl;
    cout << "float\t\t" << sizeof(float) << endl;
    cout << "double\t\t" << sizeof(double) << endl;
    cout << "long\t\t" << sizeof(long) << endl;
    cout << "short\t\t" << sizeof(short) << endl; */

/*     string current_str,pre_string;
    bool b1 = true;

    while (cin >> current_str)
    {
        if (current_str == pre_string)
        {
            b1 = false;
            cout << "连续出现的字符串是:" << current_str << endl;
            break;
        }
        pre_string = current_str;
    }
    if (b1)
    {
        cout <<  "没有连续的字符串出现" << endl;
    } */


/*     int a = 1,b=2;
    int num;
    exchange(&a,&b);
    cout << a << endl;
    cout << b << endl;
    int y = find_char("asdoffoss",'o',num);
    cout << "y= " << y << endl;
    cout << "num = " << num << endl; */
/*     string str = "sfjkldfbsdk";
    //cin >> str;
    isup("hgshshas");
    changeTolower(str);
    return 0; */
/*     vector<int> v1{1,2,3,45,6,67,88,99};
    print(v1,0); */
    
/*     int i = 5 ,j =10;
    decltype(func1)*p1 = func1,*p2 = func2;
    vector<decltype(func1)*> vF = {p1,p2};
    for(auto p :vF)
    {
        Compute(i,j,p);

    } */
    size_t a = 9;
    size_t b = sizeof(a);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl; 
    return 0;
    
    
}