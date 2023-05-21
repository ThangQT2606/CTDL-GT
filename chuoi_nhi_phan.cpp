#include <bits/stdc++.h>

using namespace std;

void generateBinaryStrings(string &str, int index)
{
    if (index == str.size())
    {
        cout << str << endl;
        return;
    }
    if (str[index] == '?')
    {
        str[index] = '0';
        generateBinaryStrings(str, index + 1);

        str[index] = '1';
        generateBinaryStrings(str, index + 1);
        str[index] = '?'; 
    }
    else
    {
        generateBinaryStrings(str, index + 1);
    }
}

int main()
{
    int t; cin >> t;
    // cin.ignore();
    while(t--)
    {
        string str;
        cin >> str;
        generateBinaryStrings(str, 0);
    }
}