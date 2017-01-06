#include <iostream>
#include <cstdio>
int main()
{

    int participants, budget, hotels, weeks;
    while(std::scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) == 4)
    {
        int price_per_person, beds_per_week, min_cost = -1, sum = 0;
        for(int i = 0; i<hotels; i++)
        {
            sum = 0;
            std::cin >> price_per_person;
            for(int j = 0; j<weeks; j++)
            {
                std::cin >> beds_per_week;
                if(beds_per_week >= participants) {
                    sum = price_per_person*participants;
                    if(min_cost == -1) min_cost = sum;
                    else if(sum < min_cost) min_cost = sum;
                }
            }

        }

        if(min_cost == -1 || min_cost > budget) std::cout << "stay home" << std::endl;
        else std::cout << min_cost << std::endl;
    }


    return 0;
}

