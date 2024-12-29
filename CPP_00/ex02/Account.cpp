/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:44:06 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/29 11:50:28 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <ctime>

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	std::time_t time;
	std::tm     *now;

	time = std::time(0);
	now = std::localtime(&time);
	std::cout << "[" << now->tm_year + 1900;
	if (now->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << now->tm_mon + 1;
	if (now->tm_mday < 10)
		std::cout << "0";
	std::cout << now->tm_mday << "_";
	if (now->tm_hour < 10)
		std::cout << "0";
	std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0";
	std::cout << now->tm_min;
	if (now->tm_sec < 10)
		std::cout << "0";
	std::cout << now->tm_sec << "] ";
	
}

void    Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
				<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void    Account::displayStatus(void)  const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << "\n";
}

void    Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit
				<< ";amount:" << checkAmount() + deposit << ";nb_deposits:" << _nbDeposits + 1 << "\n";
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits +=1;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

bool    Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (checkAmount() - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
					<< ";withdrawal:refused" << "\n";
		return (false);
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:" << withdrawal
				<< ";amount:" << checkAmount() - withdrawal << ";nb_withdrawals:" << _nbWithdrawals + 1 << "\n";
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	return (true);
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int  i;

	_accountIndex = i++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << "\n";
}