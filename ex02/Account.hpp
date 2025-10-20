// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <utility>

class Account {

public:

	typedef Account		t;

	// --->getters<--- bank
	static int	getNbAccounts( void )		{return _nbAccounts;};
	static int	getTotalAmount( void )		{return _totalAmount;};
	static int	getNbDeposits( void )		{return _totalNbDeposits;};
	static int	getNbWithdrawals( void )	{return _totalNbWithdrawals;};

	// --->getters<--- account
	int	get_accountIndex( void )		{return _accountIndex;};
	int	get_amount( void )				{return _amount;};
	int	get_nbDeposits( void )			{return _nbDeposits;};
	int	get_nbWithdrawals( void )		{return _nbWithdrawals;};

	Account( int initial_deposit )
	{
		_accountIndex = _nbAccounts;
		_nbAccounts++;
		_amount = initial_deposit;
		_totalAmount += initial_deposit;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
	};
	~Account( void );

	void	makeDeposit( int deposit )
	{
		if (deposit > 0)
		{
			//bank
			_totalAmount += deposit;
			_totalNbDeposits++;
			//account
			_amount += deposit;	
			_nbDeposits++;
		}
	}

	bool	makeWithdrawal( int withdrawal )
	{
		if (withdrawal < 0 || withdrawal > _amount || _totalAmount < withdrawal)
			return false;
		//bank
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		//account
		_amount -= withdrawal;	
		_nbWithdrawals++;
		return true;
	}
	
	int		checkAmount( void ) const; // display total amount of money in the bank
	//index:0;amount:42;deposits:0;withdrawals:0
	void	displayStatus( void )const {
		std::cout<<"index:"<< _accountIndex <<";";
		std::cout<<"amount:"<< _amount <<";";
		std::cout<<"deposits:"<< _accountIndex <<";";
		std::cout<<"withdrawals:"<< _accountIndex <<std::endl;
	};
	// display info of the bank the sum off all the account info


private:
	//info related to the bank in general
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );
	//info related to an account
	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	// Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
