#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string s;

    while(std::cin >> s) {
        std::stringstream outp;
        std::string::iterator re = s.begin();
        int scope = 0;
        while(re != s.end()) {
            if(*re == '\"') {
                outp << ((!scope) ? (scope++, "``"): (scope--, "''"));
            }
            else {
                outp << *re;
            }
            re++;
        }
        std::cout << outp.str() << std::endl;
        s.clear();
        outp.clear();
    }

    return 0;
}


//Note, doesn't work with UVa judge, submitted this instead, written
// in a more familiar language
/*

#include <string.h>
#include <stdio.h>

int main() {
char c; int count = 1;
while((c = getchar()) != EOF) {
if(c== '\"'){
printf("%s", (count ? (count--, "``") : (count++, "''")));
}
else printf("%c", c);
}
return 0;
}

*/
