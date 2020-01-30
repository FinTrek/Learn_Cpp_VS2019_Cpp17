#include <iostream>
#include <string>
//#include <functional>

int main()
{
    std::string favoriteFruit{ "grapes" };

    // Explicitly, the two lambdas below can be declared as std::function<void()> (including <functional> header)
    //
    // Note: the lambda functors are instantiated here, that is their constructor is called at the point of their definition (i.e. here),
    // wherease, their call (lines 28-29) is a call of their overloaded operator().

    auto printFavoriteFruitValueCaptured{
      [=]() {
        std::cout << "in printFavoriteFruitValueCaptured: I like " << favoriteFruit << '\n';
      }
    };

    auto printFavoriteFruitReferenceCaptured{
      [&]() {
        std::cout << "in printFavoriteFruitReferenceCaptured: I like " << favoriteFruit << '\n';
      }
    };

    favoriteFruit = "bananas with chocolate";

    printFavoriteFruitValueCaptured();
    printFavoriteFruitReferenceCaptured();

    std::cout << "in main: I like " << favoriteFruit << '\n';

    return 0;
}