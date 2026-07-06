#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
    int accountNumber;
    std::string firstName;
    std::string lastName;
    std::string pin;
    double balance;

public:
    Account();
    Account(
        int accountNumber,
        const std::string &firstName,
        const std::string &lastName,
        const std::string &pin,
        double balance);

    void input();
    void display() const;

    // Getter method to access the account number in private
    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPin() const;
    double getBalance() const;

    // Setter method to modify the account number in private
    void setAccountNumber(int accountNumber);
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setPin(const std::string &pin);
    void setBalance(double balance);
};

#endif
