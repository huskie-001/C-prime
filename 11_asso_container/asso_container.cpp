#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
using namespace std;
string &trans(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
        {
            s[p] = s[p] - ('A' - 'a');
        }
        else if (s[p] == '.' || s[p] == ',')
        {
            s.erase(p, 1);
        }
    }
    return s;
}
void word_count(const string &file)
{
    ifstream in(file);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        return;
    }
    map<string, size_t> word_count;
    string word;
    while (in >> word)
    {
        //++word_count[trans(word)];
        auto ret = word_count.insert({word,0});
        if (!ret.second)
        {
            ++ret.first->second;
        }
        
    }
    for (const auto &w : word_count)
    {
        cout << w.first << "出现了" << w.second << "次" << endl;
    }
}
void add_family(map<string, vector<pair<string,string>>> &families, const string &family)
{
    if (families.find(family) == families.end())
    {
        families[family] = vector<pair<string,string>>();
    }
}
void add_child(map<string, vector<pair<string,string>>> &families, const string &family,const string &child,const string &birthday)
{
    families[family].push_back({child,birthday});
}
// 11.9
void word2line(const string &s)
{
    ifstream in(s);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    map<string, list<int>> word_line;
    string line;
    string word;
    int lineno = 0;
    while (getline(in, line))
    {
        lineno++;
        istringstream l_in(line);
        while (l_in >> word)
        {
            word_line[trans(word)].push_back(lineno);
        }
    }
    for(const auto &w:word_line)
    {
        cout << w.first << "所在行：";
        for(const auto &i : w.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
//11.12
void pusnback_pair(const string &s)
{
    ifstream in(s);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    vector<pair<string,int>> data;
    string st;
    int v;
    while (in >> st && in >> v)
    {
        data.push_back(pair<string,int>(st,v));
    }
    for(const auto &d:data)
    {
        cout << d.first << " " << d.second << endl;
    }
    
}
//11.31
void remove_author(multimap<string,string> &books,const string &author)
{
    auto pos = books.equal_range(author);
    if (pos.first == pos.second)
    {
        cout << "没有" << author << "这个作者" << endl; 
    }
    else
    {
        books.erase(pos.first,pos.second);
    }
}
void print_books(multimap<string,string> &books,const string &author)
{
    for(auto &b:books)
    {
        cout << b.first << " " << "《 " << b.second << " 》" << endl;
    }
}
map<string,string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;
    string value;
    while (map_file >> key && map_file >> value)
    {
        if (value.size() > 1)
        {
            trans_map[key] = value;
        }
        else
        {
            throw runtime_error("no rule for " + key);
        }
        
    }
    return trans_map;
}
const string &transform(const string &s,const map<string,string> &m)
{   
    auto map_it = m.find(s);
    if (map_it != m.cend())
    {
        return map_it->second;
    }
    else
    {
        return s;
    }
}
void word_transform(ifstream &map_file,ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input,text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word,trans_map);
            
        }
        cout << endl;
        
    }
    
}
int main()
{
    // word_count("../vector.txt");
/*     map<string, vector<pair<string,string>>> families;
    add_family(families, "张");
    add_child(families, "张", "一","1970");
    add_child(families, "张", "二","1980");
    add_child(families, "张", "三","1990");
    add_child(families, "王", "四","2020");
    for (auto &f : families)
    {
        cout << f.first << "家的孩子：";
        for (auto &c : f.second)
        {
            cout << c.first << "的生日是" << c.second << " ";
        }
        cout << endl;
    } */
    //word2line("../vector.txt");
    //pusnback_pair("../pair.txt");
/*     multimap<string,string> author;
    author.insert({"n","m"});
    author.insert({"a","b"});
    author.insert({"n","m"});
    for(auto &a:author)
    {
        cout << a.first << " " << a.second << endl;
    } */
    ifstream map_file("../map_file.txt");
    ifstream input("../input.txt");
    word_transform(map_file,input);
    return 0;
}