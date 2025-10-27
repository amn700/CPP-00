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
#include "Account.hpp"

class Account {

public:

	typedef Account		t;

	// --->getters<--- bank
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );

	// --->getters<--- account
	int	get_accountIndex( void );
	int	get_amount( void );
	int	get_nbDeposits( void );
	int	get_nbWithdrawals( void );

	Account( int initial_deposit );


	void	makeDeposit( int deposit );

	bool	makeWithdrawal( int withdrawal );
	
	int		checkAmount( void ) const; // display total amount of money in the bank
	//index:0;amount:42;deposits:0;withdrawals:0
	void	displayAccountsInfos( void ) const;
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


	~Account( void );
// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
