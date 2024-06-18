class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (flowerbed[0] == 0) {
            if (flowerbed.size() > 1) {
                if (flowerbed[1] == 0) {
                    flowerbed[0] = 1;
                    n--;
                }
            } else {
                flowerbed[0] = 1;
                n--;
            }
        }

        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (n == 0) 
                break;

            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        if (flowerbed.size() > 1) {
            if (flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0) {
                flowerbed[flowerbed.size() - 1] == 1;
                n--;
            }
        } 
        
        if (n > 0) {
            return false;
        }

        if (flowerbed.size() == 1) {
            return true;
        }
        if (flowerbed[flowerbed.size() - 1] == 1 &&
            flowerbed[flowerbed.size() - 2] == 1) {
            return false;
         } 

        return true;
    }
};