#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
bool ifequal(vector<int> &vec, list<int> &list)
{
    if (vec.size() != list.size())
    {
        return false;
    }
    auto v1 = vec.begin();
    auto v2 = vec.end();
    auto l1 = list.begin();
    for (; v1 != v2; v1++, l1++)
    {
        if (*v1 != *l1)
        {
            return false;
        }
    }
    return true;
}
void print_deque(deque<string> &sdeq)

{
    string word;

    while (cin >> word)
    {
        if (word == "q")
        {
            break;
        }

        sdeq.push_front(word);
    }
    for (deque<string>::iterator it = sdeq.begin(); it != sdeq.end(); it++)
    {
        cout << *it << endl;
    }
}
void print_list(list<string> &slist)
{
    string word;

    while (cin >> word)
    {
        if (word == "q")
        {
            break;
        }

        slist.push_front(word);
    }
    for (const auto &s : slist)
    {
        cout << s << endl;
    }
}
void list_to_deque(list<int> &ilist, deque<int> &ideq1, deque<int> &ideq2)
{
    for (const auto &l : ilist)
    {
        if (l % 2 == 0)
        {
            ideq1.push_back(l);
        }
        else
        {
            ideq2.push_back(l);
        }
    }
}
void insert_vec(vector<int> &ivec, int val)
{
    int new_ele = 0;
    for (auto it = ivec.begin(); it != (ivec.begin() + ivec.size() / 2 + new_ele); it++)
    {
        if (*it == val)
        {
            ivec.insert(it, 2 * val);
            it++;
        }
    }
}
void erase_arr(int arr[], list<int> &ilist, vector<int> &ivec)
{
    ilist.assign(arr, arr + 9);
    ivec.assign(arr, arr + 9);
    auto it1 = ilist.begin();
    auto it2 = ivec.begin();
    while (it1 != ilist.end())
    {
        if (*it1 % 2)
        {
            it1 = ilist.erase(it1);
        }
        else
        {
            ++it1;
        }
    }
    while (it2 != ivec.end())
    {
        if (*it2 % 2 == 0)
        {
            it2 = ivec.erase(it2);
        }
        else
        {
            ++it2;
        }
    }
}
void copy_odd_even(list<int> &ilist)
{
    list<int>::iterator it = ilist.begin();
    while (it != ilist.end())
    {
        if (*it & 1)
        {
            it = ilist.insert(it, *it);
            it++;
            it++;
        }
        else
        {
            it = ilist.erase(it);
        }
    }
}
void replace_string(string &s, const string oldval, const string newval)
{
    auto l = oldval.size();
    if (!l)
    {
        return;
    }
    auto it = s.begin();
    while (it <= s.end() - 1)
    {
        auto it1 = it;
        auto it2 = oldval.begin();
        while (it2 != oldval.end() && *it1 == *it2)
        {
            it1++;
            it2++;
        }

        if (it2 == oldval.end())
        {
            it = s.erase(it, it1);
            if (!newval.empty())
            {
                it2 = newval.end() - 1;

                while (it2 >= newval.begin())
                {
                    it = s.insert(it, *it2);
                    it2--;
                }
            }
        }
        else
        {
            it++;
        }
    }
}
void find_char(string &s,const string &chars)
{
    cout << "在" << s << "中查找" << chars << "字符" << endl;
    string::size_type pos = 0;
    while ((pos = s.find_first_of(chars,pos))!= string::npos)
    {
        cout << "pos: " << pos << " ,char: " << s[pos] << endl;
        pos++;
    }
    
}
int main()
{
    /*     vector<int> ivec{1,24,566,7,78,98,953,6654};
        list<int> ilist{1,2,3,4,5,6,7,8};
        vector<double>dvec(ilist.begin(),ilist.end());

        vector<double>dvec1(ivec.begin() + 1,ivec.end() -1);

        for(auto it:dvec1)
        {
            cout << it << endl;
        } */
    /*     list<char *>slist{"hello","world","!"};
        vector<string> svec;
        svec.assign(slist.begin(),slist.end());
        cout << svec.capacity() << " " << svec.size() << " " << svec[0] << svec[svec.size()-1] << endl; */
    // cout << ifequal(ivec,ilist) << endl;
    /*     deque<string> sdeq;
        list<string> slsit;
        print_list(slsit); */
    /*     list<int> ilist{1,2,3,4,5,6,7,8,9};
        deque<int> iduq1;
        deque<int> iduq2;
        list_to_deque(ilist,iduq1,iduq2);
        for(const auto &i:iduq1)
        {
            cout << i << endl;
        }
        for(const auto &in:iduq2)
        {
            cout << in << endl;
        } */
    /*     vector<int> ivec{1,2,3,4};
        cout << ivec.at(0) << endl;
        cout << ivec.front() << endl;
        cout << ivec.back() << endl; */
    /*     insert_vec(ivec,1);
        for(const auto &i:ivec)
        {
            cout << i << endl;
        } */
    /*     list<int> ilist;
        vector<int> ivec;
        int ia[] = {0,1,2,3,45,6,7,8,9,3};
        erase_arr(ia,ilist,ivec);
        for(const auto il:ilist)
        {
            cout << "list" << il << " ";
        }
        cout << endl;
        for(const auto iv:ivec)
        {
            cout << "vector" << iv << " ";
        } */
    /*     list<int> ilist{0,1,2,3,4,5,6,7,8,9};
        vector<int> ivec{1,2,35,6,77545,454};
        copy_odd_even(ilist);
        for(const auto i:ilist)
        {
            cout << i << " ";
        }
        ivec.reserve(50);
        cout << "内存空间：" << ivec.capacity() << endl; */
    //string s = "guoshuai";
    //replace_string(s,"shuai","zhang");
    //find_char(s,"o");
    //string name = "zh";
    //cout << s.find(name) << endl;
    deque<int>sh{1,2,3,4,5,6,7};
    queue<int> stk(sh);
    while (!stk.empty())
    {
        int back = stk.back();
        int front = stk.front();
        cout << back << endl;
        cout << front << endl;
        stk.pop();

    }
    
    return 0;
}