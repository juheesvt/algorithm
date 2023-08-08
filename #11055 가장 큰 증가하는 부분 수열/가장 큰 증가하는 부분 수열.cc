#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1001;


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cache[MAX] = {0, };
    int arr[MAX] = {0, };

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        cache[i] = arr[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            // 현재 기준 비교값보다 이전까지의 합 + 현재 값이 크면 갱신
            if (arr[j] < arr[i] && cache[i] < cache[j] + arr[i]) {
                cache[i] = cache[j] + arr[i];
            }
        }
    }
    cout << *max_element(cache, cache + n);


    return 0;
}