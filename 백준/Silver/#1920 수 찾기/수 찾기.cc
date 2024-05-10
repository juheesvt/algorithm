#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
int tmp;
unordered_map<int, int> numMap;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        numMap.insert({tmp, 1});
    }
   scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        printf("%d\n", numMap[tmp]);
    }

    return 0;
}
