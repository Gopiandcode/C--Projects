#include <iostream>

class Bank {
public:
    void give(Bank& b, int value) {
        this->reserve -= value;
        b += value;
    }
    bool check() {
        if(reserve<0) return true;
        return false;
    }
    Bank(int id, int reserve) : id(id), reserve(reserve){}
    Bank() : id(0),reserve(0) {}
    Bank operator+=(int value) {
        this->reserve += value;
    }
    int id;
    int reserve;

};

int main()
{
    int B, N;
    while(std::cin >> B >> N, B+N > 0) {
        Bank bank_store[B];

        //initialize the banks
        for(int i = 0; i<B; i++) {
            int val;
            std::cin >> val;
            bank_store[i].~Bank();
            new(&bank_store[i]) Bank(i,val);
        }

        //perform the transactions
        int debtor, creditor, value;
        for(int i = 0; i<N; i++) {
            std::cin >> creditor >> debtor >> value;
            debtor -= 1;
            creditor -= 1;
            bank_store[creditor].give(bank_store[debtor], value);
        }

        //check for errors
        bool flag = false;
        for(int i = 0; i<B; i++) {
            if(bank_store[i].check()) flag = true;
        }
        if(flag) std::cout << "N" << std::endl;
        else std::cout << "S" << std::endl;

    }

    return 0;
}


