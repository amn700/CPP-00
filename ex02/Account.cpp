#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account :: Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout<<" index:"<< _accountIndex <<";";
    std::cout<<"amount:"<< checkAmount() <<";";
    std::cout<<"created"<<std::endl;
}

Account :: ~Account( void )
{
    _displayTimestamp();
    std::cout<<" index:"<< _accountIndex <<";";
    std::cout<<"amount:"<< checkAmount() <<";";
    std::cout<<"closed"<<std::endl;
}

int	Account:: getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account :: getTotalAmount( void )
{
    return _totalAmount;
}

int Account :: getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account ::	getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int	Account :: checkAmount( void ) const
{
    return _amount;
}

void	Account :: makeDeposit( int deposit )
{
    if (deposit > 0)
    {
        int p_amount = checkAmount();
        _totalAmount += deposit;
        _totalNbDeposits++;
        _amount += deposit;	
        _nbDeposits++;

        _displayTimestamp();
        std::cout<<" index:"<< _accountIndex <<";";
        std::cout<<"p_amount:"<< p_amount <<";";
        std::cout<<"deposit:"<< deposit <<";";
        std::cout<<"amount:"<< checkAmount() <<";";
        std::cout<<"nb_deposits:"<< _nbDeposits <<std::endl;
    }
}

bool Account ::	makeWithdrawal( int withdrawal )
{
    if (withdrawal < 0 || withdrawal > checkAmount())
    {
        _displayTimestamp();
        std::cout<<" index:"<< _accountIndex <<";";
        std::cout<<"p_amount:"<< checkAmount() <<";";
        std::cout<<"withdrawal:"<< "refused"<<std::endl;
        return false;
    }
    int p_amount = checkAmount();
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _amount -= withdrawal;	
    _nbWithdrawals++;
    _displayTimestamp();
    std::cout<<" index:"<< _accountIndex <<";";
    std::cout<<"p_amount:"<< p_amount <<";";
    std::cout<<"withdrawal:"<< withdrawal <<";";
    std::cout<<"amount:"<< checkAmount() <<";";
    std::cout<<"nb_withdrawals:"<< _nbWithdrawals <<std::endl;

    return true;
}

void    Account :: _displayTimestamp(void)
{
    //YYYYMMDD_HHMMSS
    char buf[20];
    time_t now = std::time(NULL);
    std::tm tm = *std::gmtime(&now);
    std::strftime(buf, 20, "%Y%m%d_%H%M%S", &tm);
    std::cout<<"["<<buf<<"]";
}

void Account :: displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<<" index:"<< _accountIndex <<";";
    std::cout<<"amount:"<< checkAmount() <<";";
    std::cout<<"deposits:"<< _nbDeposits <<";";
    std::cout<<"withdrawals:"<< _nbWithdrawals <<std::endl;
}

void Account ::	displayAccountsInfos( void ) 
{
    _displayTimestamp();
    std::cout<<" accounts:"<< _nbAccounts <<";";
    std::cout<<"total:"<< _totalAmount <<";";
    std::cout<<"deposits:"<< _totalNbDeposits <<";";
    std::cout<<"withdrawals:"<< _totalNbWithdrawals <<std::endl;
};
