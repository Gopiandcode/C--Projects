#include <iostream>

int main()
{
    int length, a,b;
    std::cin >> length;
    for(int i = 0; i<length; i++) {
        std::cin >> a >> b;
        char op = (a == b) ? '=' : ((a > b) ? '>' : '<');
        std::cout << op  << std::endl;
    }
    return 0;
}
