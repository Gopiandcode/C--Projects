#include <iostream>
double loan_amount, down_payment, pay_per_month, money_owed, car_value, depreciation;
int months, records, current_month, i;

int main() {
    while(std::cin >> months >> down_payment >> loan_amount >> records, months >0) {
     car_value = loan_amount + down_payment;
     pay_per_month = loan_amount/months;

     std::cin >> current_month >> depreciation;
     if(records >1) std::cin >> months;
     else months = 0;

    car_value *= (1-depreciation);
    current_month = 0;
    i = 1;

     while(loan_amount > car_value) {
        current_month++;
        //check if the current month is the next month with value defined
        if(current_month == months) {
            std::cin >> depreciation;
            i++;
            if(i<records){
                std::cin >> months;
            }
            else months = 0;
        }
        car_value *= (1-depreciation);
        loan_amount -= pay_per_month;
     }
     while(i<records) {
        std::cin>>depreciation;
        i++;
        if(i>= records) break;
        std::cin >> months;
     }

    std::cout << current_month;
    if(current_month != 1) std::cout << " months" << std::endl;
    else std::cout << " month" << std::endl;

    }
    return 0;
}
