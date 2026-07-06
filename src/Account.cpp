#include <iostream>
#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    balance = 0.0;
}

Account::Account(
    int accountNumber,
    const std::string &firstName,
    const std::string &lastName,
    const std::string &pin,
    double balance)
{
    this->accountNumber = accountNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->pin = pin;
    this->balance = balance;
}

void Account::input()
{
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter pin: ";
    std::cin >> pin;
    std::cout << "Enter balance: ";
    std::cin >> balance;
}
void Account::display() const
{
    std::cout << "\n========== Account Details ==========\n";
    std::cout << "Account Number : " << accountNumber << '\n';
    std::cout << "First Name     : " << firstName << '\n';
    std::cout << "Last Name      : " << lastName << '\n';
    std::cout << "Balance        : ₹" << balance << '\n';
    std::cout << "=====================================\n";
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

std::string Account::getFirstName() const
{
    return firstName;
}

std::string Account::getLastName() const
{
    return lastName;
}

std::string Account::getPin() const
{
    return pin;
}
double Account::getBalance() const
{
    return balance;
}

// Setter

void Account::setAccountNumber(int accountNumber){
    this->accountNumber=accountNumber;
}

void Account::setFirstName(const std::string &firstName){
    this->firstName=firstName;
}

void Account::setLastName(const std::string &lastName){
     this->lastName=lastName;
}

void  Account::setPin(const std::string &pin){
    this->pin=pin;
}

void Account::setBalance(double balance){
    this->balance=balance;
}
