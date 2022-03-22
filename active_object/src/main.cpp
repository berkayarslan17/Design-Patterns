#include <iostream>
#include <algorithm>
#include <vector>

void print(std::vector<int> a)
{
    for (auto val : a)
        std::cout << val << ' ';
    std::cout << '\n';
}
int main()
{
    auto compare_ints = [](int a, int b)
    { return a < b; };

    std::vector<int> my_vec{4, 8, 7, 6, 5, 9, 11};
    print(my_vec);

    std::sort(my_vec.begin(), my_vec.end(), compare_ints);
    print(my_vec);

    return 0;
}