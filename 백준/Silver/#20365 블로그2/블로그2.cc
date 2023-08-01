#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 36;


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int red = 0, blue = 0;
    for (int i=1; i<str.length(); i++) {
            if ((str[i - 1] == 'B' && str[i] == 'R') || (str[i] == 'B' && i == str.length() - 1)) {
                blue++;
            }  
            if ((str[i - 1] == 'R' && str[i] == 'B') ||  (str[i] == 'R' && i == str.length() - 1)) {
                red++;
            }
        }
    cout << min(red, blue) + 1;
    return 0;
}