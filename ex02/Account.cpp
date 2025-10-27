#include "phonebook.hpp"
#include "Account.hpp"

Account :: Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
};

void	Account :: makeDeposit( int deposit )
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

bool Account ::	makeWithdrawal( int withdrawal )
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

void Account ::	displayAccountsInfos( void ) const {
    std::cout<<"index:"<< _accountIndex <<";";
    std::cout<<"amount:"<< _amount <<";";
    std::cout<<"deposits:"<< _accountIndex <<";";
    std::cout<<"withdrawals:"<< _accountIndex <<std::endl;
};//index:0;amount:42;deposits:0;withdrawals:0

int	Account :: checkAmount( void ) const
{
    return 1;
}

// --->getters<--- bank
int	Account :: getNbAccounts( void )		{return _nbAccounts;};
int	Account :: getTotalAmount( void )		{return _totalAmount;};
int Account :: getNbDeposits( void )		{return _totalNbDeposits;};
int Account ::	getNbWithdrawals( void )	{return _totalNbWithdrawals;};

// --->getters<--- account
int Account ::	get_accountIndex( void )		{return _accountIndex;};
int Account ::	get_amount( void )				{return _amount;};
int Account ::	get_nbDeposits( void )			{return _nbDeposits;};
int Account ::	get_nbWithdrawals( void )		{return _nbWithdrawals;};


/*
creation
status
deposit
status
withdrawal
status
closure
*/