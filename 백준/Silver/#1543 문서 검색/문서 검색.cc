#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string document, target;

    getline(cin, document);
    getline(cin, target);

    int count = 0;
    int idx = 0;
    while (idx < document.size())
    {
        if (document.substr(idx, target.size()) == target)
        {
            count++;
            idx += target.size();
        }
        else
        {
            idx++;
        }
    }
    cout << count;
    return 0;
}
