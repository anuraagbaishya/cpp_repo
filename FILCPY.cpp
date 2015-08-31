#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream o("1.txt");
    ifstream ob("2.txt");
    char ch;
    while(ob.eof()==0)
    {
        ob.get(ch);
        o.put(ch);
        cout<<ch;
    }
    o.close();
    ob.close();
}