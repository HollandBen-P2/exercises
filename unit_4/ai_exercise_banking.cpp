#include <iostream>
#include <cassert>
#include <string>

int main();

class Account {
    public:
    Account(unsigned long account_number, std::string account_holder, double balance);
    ~Account();
    double deposit(double amount);
    double withdraw(double amount);
    double get_balance() const;
    std::string __str__() const;
    
    private:
    unsigned long account_number_;
    std::string account_holder_;
    double balance_;
};

Account::Account(unsigned long account_number, std::string account_holder, double balance = 0.0) : 
    account_number_{account_number}, 
    account_holder_{account_holder}, 
    balance_{balance} {
    //empty
}

Account::~Account() {
    //empty desctructor, since no dynamic memory allocation was used.
}

double Account::deposit(double amount) {
    balance_ += amount;
    std::cout << "Amount deposited: " << amount;
    std::cout << Account::__str__();
    return balance_;
}

double Account::withdraw(double amount) {
    balance_ -= amount;
    std::cout << "Amount withdrawn: " << amount;
    std::cout << Account::__str__();
    return balance_;
}

double Account::get_balance() const {
    return balance_;
}

std::string Account::__str__() const {
    std::cout << "Account #" << account_number_ << " is held by " << account_holder_ << ", with a balance of $" << balance_ << "." << std::endl;
}