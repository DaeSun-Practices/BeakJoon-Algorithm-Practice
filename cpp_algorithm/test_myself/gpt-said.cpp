#include <iostream>
using namespace std;

int main() {
    int size_num = 9;
    int radius = size_num / 2;

    for (int i = 0; i < size_num; i++) {
        int stars, spaces;

        if (i <= radius) { // 위쪽
            spaces = radius - i;
            stars  = 2 * i + 1;
        } else { // 아래쪽
            spaces = i - radius;
            stars  = 2 * (size_num - i - 1) + 1;
        }

        cout << string(spaces, ' ') << string(stars, '*') << endl;
    }

    return 0;
}
