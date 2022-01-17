#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    string typed;

    cin >> name;
    cin >> typed;
    int j = 0;
    int i = 0;
    int cntn = 0;
    int cntt = 0;
    bool outp = true;
    bool ou = true;

    while (i < name.size() && j < typed.size())
    {

        if ((name[i] == typed[j]) && (i != name.size() - 1))
        {
            if (name[i] == name[i + 1] || typed[j] == typed[j + 1])
            {
                if (name[i] == name[i + 1])
                {
                    cntn++;
                    i++;
                }
                else if (typed[j] == typed[j + 1])
                {
                    cntt++;
                    j++;
                }
            }
            else if (cntt >= cntn)
            {

                cntn = 0;
                cntt = 0;
                i++;
                j++;
            }
            else
            {
                outp = false;
                cout << "False";
                break;
            }
        }
        else if ((i == name.size() - 1) && (name[i] == typed[j]))
        {
            if (j != typed.size() - 1)
            {
                if (typed[j] == typed[j + 1])
                {
                    cntt++;
                    j++;
                }
                else
                {
                    outp = false;
                    cout << "False";
                    break;
                }
            }
            else if (name[i] == typed[j])
            {
                outp = true;
            }
            else
            {
                outp = false;
                cout << "false";
            }
        }
        else
        {
            outp = false;
            cout << "False";
            break;
        }
    }
    if (outp)
    {
        cout << "True";
    }

    return 0;
}