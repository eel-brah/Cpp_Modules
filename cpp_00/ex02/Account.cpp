#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();

  std::cout << "accounts:" << Account::_nbAccounts << ';'
            << "total:" << Account::_totalAmount << ';'
            << "deposits:" << Account::_totalNbDeposits << ';'
            << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
  Account::_displayTimestamp();

  Account::_accountIndex = Account::_nbAccounts;
  Account::_amount = 0;
  Account::_nbDeposits = 0;
  Account::_nbWithdrawals = 0;

  Account::_nbAccounts++;

  std::cout << "index:" << Account::_accountIndex << ';'
            << "amount:" << Account::_amount << ';' << "created" << std::endl;
}

Account::Account(int initial_deposit) {
  Account::_displayTimestamp();

  Account::_accountIndex = Account::_nbAccounts;
  Account::_amount = initial_deposit;
  Account::_nbDeposits = 0;
  Account::_nbWithdrawals = 0;

  Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;

  std::cout << "index:" << Account::_accountIndex << ';'
            << "amount:" << Account::_amount << ';' << "created" << std::endl;
}

Account::~Account(void) {
  Account::_displayTimestamp();

  std::cout << "index:" << Account::_accountIndex << ';'
            << "amount:" << Account::_amount << ';' << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();

  Account::_nbDeposits++;
  Account::_amount += deposit;

  Account::_totalNbDeposits++;
  Account::_totalAmount += deposit;

  std::cout << "index:" << Account::_accountIndex << ';'
            << "p_amount:" << Account::_amount - deposit << ';'
            << "deposit:" << deposit << ';' << "amount:" << Account::_amount
            << ';' << "nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();

  std::cout << "index:" << Account::_accountIndex << ';'
            << "p_amount:" << Account::_amount << ';';
  if (Account::_amount >= withdrawal) {
    Account::_nbWithdrawals++;
    Account::_amount -= withdrawal;

    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ';'
              << "amount:" << Account::_amount << ';'
              << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
    return true;
  } else
    std::cout << "withdrawal:"
              << "refused" << std::endl;
  return false;
}

int Account::checkAmount(void) const { return Account::_amount; }

void Account::displayStatus(void) const {
  Account::_displayTimestamp();

  std::cout << "index:" << Account::_accountIndex << ';'
            << "amount:" << Account::_amount << ';'
            << "deposits:" << Account::_nbDeposits << ';'
            << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t time = std::time(NULL);

  std::cout << std::setfill('0') << "[" << 1900 + std::localtime(&time)->tm_year
            << std::setw(2) << 1 + std::localtime(&time)->tm_mon << std::setw(2)
            << std::localtime(&time)->tm_mday << "_" << std::setw(2)
            << std::localtime(&time)->tm_hour << std::setw(2)
            << std::localtime(&time)->tm_min << std::setw(2)
            << std::localtime(&time)->tm_sec << "] ";
}
