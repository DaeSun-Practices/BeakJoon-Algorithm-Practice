#include <bits/stdc++.h>

using namespace std;

bool reverse_sort(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    int N, M;
    cin >> N >> M;

    vector<int> mask_vector;

    for (int i = 0; i < N - M; i++)
    {
        mask_vector.push_back(0);
    }

    int mask_priority = 1;
    for (int i = 0; i < M; i++)
    {
        mask_vector.push_back(mask_priority);
        mask_priority++;
    }

    vector<int> number_vector;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        number_vector.push_back(x);
    }

    sort(number_vector.begin(), number_vector.end(), reverse_sort);

    set<vector<int>> permutation_set;
    vector<vector<int>> pen_list;
    do
    {
        vector<int> current_permutation;
        for (int priority = M; priority > 0; priority--)
        {
            for (int i = 0; i < N; i++)
            {
                if (mask_vector[i] == priority)
                {
                    current_permutation.push_back(number_vector[i]);
                    break;
                }
            }
        }

        if (permutation_set.find(current_permutation) == permutation_set.end())
        {
            permutation_set.insert(current_permutation);
            pen_list.push_back(current_permutation);
        }

    } while (next_permutation(mask_vector.begin(), mask_vector.end(), less()));



    sort(pen_list.begin(), pen_list.end());
    for (int i=0; i<pen_list.size(); i++){
        for (int j: pen_list[i]){
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}