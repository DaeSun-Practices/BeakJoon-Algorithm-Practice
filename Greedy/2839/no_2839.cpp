#include <iostream>

using namespace std;

int main(){
    int N, number_of_bags, number_of_fives, remain_of_three;

    cin >> N;
    number_of_fives = N/5;
    
    for(int fives=number_of_fives; fives >= 0; fives--){
        remain_of_three = N - 5*fives;
        if (remain_of_three % 3 == 0){
            number_of_bags = fives + remain_of_three/3;
            cout << number_of_bags;
            return 0;
        }
    }

    cout << -1;

    return 0;
}