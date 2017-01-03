#include <iostream>
#include <string>
int main() {
int queries, bordx, bordy, x ,y;
    while(std::cin >> queries, queries != 0) {
        std::cin >> bordx >> bordy;
        while(queries != 0) {
            std::cin >> x >> y;
            if((x == bordx) || (y == bordy)) std::cout << "divisa" << std::endl;
            else {
                std::string outp = (x > bordx) ? ((y<bordy)? "SE": "NE") : ((y<bordy)?"SO":"NO");
                std::cout<<outp << std::endl;
            }

            queries--;
        }
    }
}

