#include <bits/stdc++.h>
using namespace std;

string numToString(int n)
{
    string s;
    switch (n)
    {
    case 1:
        s = "No One";
        break;
    case 2:
        s = "Yes Two";
        break;
    case 3:
        s = "Yes Three";
        break;
    case 4:
        s = "No Four";
        break;
    case 5:
        s = "Yes Five";
        break;
    case 6:
        s = "No Six";
        break;
    case 7:
        s = "Yes Seven";
        break;
    case 8:
        s = "No Eight";
        break;
    case 9:
        s = "Yes Nine";
        break;
    case 0:
        s = "No Zero";
        break;

    default:
        break;
    }
    return s;
}

pair<int, string> splitNum(string elements)
{
    pair<int, string> pear;
    int n = 0;
    string element = "";
    for (int i = 0; i < elements.length(); i++)
    {
        if (isdigit(elements[i]))
        {
            n = (n * 10) + elements[i];
        }
        else
        {
            element.push_back(elements[i]);
        }
    }
    pear.first = n;
    pear.second = element;
    return pear;
}

int cntVowels(string element, int count)
{
    int cnt = 0;
    for (int i = 0; i < element.length(); i++)
    {
        if (element[i] == 'a' || element[i] == 'e' || element[i] == 'i' || element[i] == 'o' || element[i] == 'u' ||
            element[i] == 'A' || element[i] == 'E' || element[i] == 'I' || element[i] == 'O' || element[i] == 'U')
        {
            cnt++;
        }
    }
    return cnt;
}

int eleScore(int cnt, string emotion)
{
    int eleScor = 0;
    if (emotion == "Happy")
    {
        eleScor = cnt * 10;
    }
    else if (emotion == "Sad")
    {
        eleScor = cnt * 5;
    }
    else if (emotion == "Neutral")
    {
        eleScor = cnt * 2;
    }
    else if (emotion == "None")
    {
        eleScor = cnt * 1;
    }
    return eleScor;
}

int main()
{
    int elementCnt;
    cin >> elementCnt;
    vector<string> elements;
    vector<string> emotion;

    for (int i = 0; i < elementCnt; i++)
    {
        string str;
        cin >> str;
        elements.push_back(str);
    }
    for (int i = 0; i < elementCnt; i++)
    {
        string str;
        cin >> str;
        emotion.push_back(str);
    }

    int elementSrc = 0;
    int vowelCnt = 0;

    for (int i = 0; i < elementCnt; i++)
    {
        pair<int, string> split = splitNum(elements[i]);
        cout << split.first << "  ";
        elementSrc += eleScore(split.first, emotion[0]);
        cout << "scr " << elementSrc;
        vowelCnt += (split.first * cntVowels(split.second, split.first));
        cout << " cnt " << vowelCnt << endl;
    }
    double greater = max(elementSrc, vowelCnt);
    double small = min(elementSrc, vowelCnt);
    int area = floor(greater / small);
    // cout << area;
    string res = numToString(area);
    cout << endl
         << res;

    return 0;
}