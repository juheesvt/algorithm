#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000001;

int check(int* light, int* current, int n) {
    for (int i=0; i<n; i++) {
        if (light[i] != current[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int light[MAX] = {0, };
    int current[MAX] = {0, };
    for (int i=0; i<n; i++) {
        cin >> light[i];
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (light[i] != current[i]) {
            cnt++;
            for (int j=0; j<=2; j++) {
                if (i + j < n) {
                    current[i + j] = 1 - current[i + j];
                }
            }
            // if (check(light, current, n)) break;
        }
    }
    cout << cnt;

    return 0;
}