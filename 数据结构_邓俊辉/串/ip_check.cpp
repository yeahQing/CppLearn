#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s = "192.168.0.1";

    int num = stoi(s);

    char c = s[0];
    
    // cout << c - '0' << endl;
    // cout << atoi(&s[2]) << endl;
    // cout << num << endl;

    for (int i = 0; i < s.size(); i++)
    {
        cout << atoi(&s[i]) << endl;
    }

    printf("%d\n", 'A' - 'A' + 10);

    cout << s.substr(0, 2) << endl; 

    return 0;
}
