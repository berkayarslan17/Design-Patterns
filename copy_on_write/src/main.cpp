// #include <gtest/gtest.h>
#include "copy_on_write.h"
#include <string>
#include <iostream>

// int add(int a, int b)
// {
//     return a + b;
// }

// TEST(add, positive)
// {
//     ASSERT_EQ(10, add(5, 5));
// }

// TEST(add, negative)
// {
//     ASSERT_EQ(-11, add(-5, -5));
// }

int main(int argc, char **argv)
{
    // ::testing::InitGoogleTest(&argc, argv);
    // RUN_ALL_TESTS();
    // return 0;

    CowPtr<std::string> string1(new std::string("Share Me"));
    std::cout << "String 1 address: " << string1 << '\n';
    std::cout << "String 1 value: " << *string1 << '\n';

    CowPtr<std::string> string2(string1);
    std::cout << "String 2 address: " << string2 << '\n';
    std::cout << "String 2 value: " << *string2 << '\n';

    CowPtr<std::string> string3(string1);
    string3->append("!");
    std::cout << "String 3 address: " << string3 << '\n';
    std::cout << "String 3 value: " << *string3 << '\n';
}
