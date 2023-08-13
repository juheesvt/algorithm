#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1001;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // cache[i] = i번째 수를 수열에 포함시켰을 때, 수열의 최대 길이
    int numbers[MAX], cache[MAX];
    for (int i=0; i<n; i++) {
        cin >> numbers[i];
        cache[i] = 1;   // 모든 수에 대해, 해당 수를 수열에 포함시켰을 때 수열의 최소 길이는 1임
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            // i 번째 숫자를 기준으로 0번째 수부터 검사하면서, cache[i]에 저장되어있는 값보다 j를 포함시켰을때의 길이가 더 길면 업데이트
            if (numbers[j] < numbers[i] && cache[i] < cache[j] + 1) {
                cache[i] = cache[j] + 1;
            }
        }
    }
    cout << *max_element(cache, cache + n);

    return 0;
}