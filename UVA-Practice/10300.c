#include <iostream>

//area/numanims * envfriend *numanims
int main() {
    int cases, farmers;

    std::cin >> cases;
    while(cases>0){
        std::cin >> farmers;
        int sum = 0;
        int sz, anims, env;

        for(int i = 0; i<farmers; i++){
            std::cin >> sz >> anims >> env;
            sum += sz*env;
        }


        std::cout << sum << std::endl;

        cases--;
    }
    return 0;
}

