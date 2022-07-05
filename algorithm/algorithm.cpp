#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <numeric>
#include <iterator>
#include "algorithm.h"
using namespace std;

string make_paural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
void print_num(vector<int> &ivec, int val)
{
    auto result = count(ivec.begin(), ivec.end(), val);
    cout << result << endl;
}
void print_snum(list<string> &slist, string chars)
{
    auto result = count(begin(slist), end(slist), chars);
    cout << result << endl;
}
int count_sum(string s)
{
    ifstream in(s, ios::in);
    if (!in)
    {
        cout << "文件读取失败！" << endl;
        return -1;
    }
    int num;
    vector<int> vi;
    while (in >> num)
    {
        vi.push_back(num);
    }
    return accumulate(vi.begin(), vi.end(), 0);
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void add(int a)
{
    auto sum = [a](int b)
    { return a + b; };
    cout << sum(1) << endl;
}
void biggirs(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    vector<string>::iterator wc = find_if(words.begin(), words.end(), [sz](const string &a)
                                          { return a.size() >= sz; });
    int count = words.end() - wc;
    //两种写法实现的功能一样
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
    for (; wc != words.end(); wc++)
    {
        cout << *wc << " ";
    }
    cout << endl;
}
void istea_itera(const string &s)
{
    vector<string> words;
    ifstream in;
    in.open(s, ios::in);
    if (!in)
    {
        cout << "打开文件失败" << endl;
        return;
    }
    /*     istream_iterator<string> in_iter(inr);
        istream_iterator<string> eof;
        while (in_iter != eof)
        {
            words.push_back(*in_iter++);
        }
        for(auto word:words)
        {
            cout << word << " ";
        } */
    string ch;
    while (in >> ch, !in.eof())
    {
        words.push_back(ch);
    }
    for (auto word : words)
    {
        cout << word << " ";
    }
    cout << endl;
}
void copy_ost()
{
    int n;
    istream_iterator<int> in_iter(cin);

    istream_iterator<int> eof;
    vector<int> vi;
    while (in_iter != eof)
    {
        vi.push_back(*in_iter++);
    }
    sort(vi.begin(), vi.end());

    ostream_iterator<int> out_iter(cout, " ");
    unique_copy(vi.begin(), vi.end(), out_iter);
}
inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn < rhs.isbn;
}
void sort_and_acc()
{
    vector<Sales_item> vs;
    istream_iterator<Sales_item> in_iter(cin);
    istream_iterator<Sales_item> eof;
    while (in_iter != eof)
    {
        vs.push_back(*in_iter++);
    }
    if (vs.empty())
    {
        cerr << "No data" << endl;
        return;
    }
    sort(vs.begin(), vs.end(), compareIsbn);
    auto l = vs.begin();
    while (l != vs.end())
    {
        auto item = *l;
        auto r = find_if(l + 1, vs.end(), [item](const Sales_item &item1)
                         { return item1.isbn != item.isbn; });
        cout << accumulate(l + 1, r, item) << endl;
        l = r;
    }
}
void in_and_out(const string in1, const string out1, const string out2)
{
    ifstream in(in1);
    if (!in)
    {
        cout << "打开输入文件失败!" << endl;
        return;
    }
    ofstream out_1(out1);
    if (!out_1)
    {
        cout << "打开输入文件失败!" << endl;
        return;
    }
    ofstream out_2(out2);
    if (!out_2)
    {
        cout << "打开输入文件失败!" << endl;
        return;
    }
    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> out1_iter(out_1, " ");
    ostream_iterator<int> out2_iter(out_2, " ");
    while (in_iter != eof)
    {
        if (*in_iter % 2)
        {
            *out1_iter++ = *in_iter;
        }
        else
        {
            *out2_iter++ = *in_iter;
        }
        in_iter++;
    }
}
void find_list()
{
    list<int> li = {0, 1, 2, 3, 0, 2, 7, 8, 0, 9};
    auto last_z = find(li.crbegin(), li.crend(), 0);
    last_z++;
    int p = 1;
    for (auto iter = li.begin(); iter != last_z.base(); p++, iter++);

    if (p >= li.size())
    {
        cout << "容器中没有0" << endl;
    }
    else
    {
        cout << "最后一个0在di" << p << "个位置" << endl;
    }
}
void rever()
{
    ostream_iterator<int> out_iter(cout," ");
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    copy(vi.begin(),vi.end(),out_iter);
    cout << endl;
    list<int> ilist;
    vector<int>::reverse_iterator re(vi.begin() + 2);
    vector<int>::reverse_iterator rb(vi.begin() + 7);
    copy(rb,re,back_inserter(ilist));
    copy(ilist.begin(),ilist.end(),out_iter);
    cout << endl;
}
int main()
{
    /*     vector<int> ivec{1,232345,45,4,5,456,332,1,1,1,1,};
        list<string> slist{"a","d","s","s","d","s"};
        print_num(ivec,1);
        print_snum(slist,"s"); */
    // vector<string> words = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    // elimDups(words);
    // stable_sort(words.begin(),words.end(),isShorter);
    // sort(words.begin(),words.end());
    /*     for(const auto &w:words)
        {
            cout << w << endl;
        }
        list<string> li;
        unique_copy(words.begin(),words.end(),back_insert_iterator(li));
        for(const auto &l:li)
        {
            cout << l << endl;
        } */
    /*     auto sum = [] (int a,int b){return a + b;};
        cout << sum(1,1) << endl; */
    // add(1);
    // add(2);

    // biggirs(words,4);
    /*     string s = "../vector.txt";
        istea_itera(s);
         */

    // copy_ost();
    // sort_and_acc();
    // in_and_out("../vector.txt","../vector2.txt","../vector3.txt");
    /*     string c;
        ifstream in("../vector.txt");
        while (in >> c,!in.eof())
        {

            cout << c << endl;
        } */
    //find_list();
    rever();
    return 0;
}