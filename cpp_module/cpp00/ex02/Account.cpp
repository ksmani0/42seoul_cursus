#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
    time_t timeStamp;
    char stamp[16];//20211009_125400 + \0

    time(&timeStamp);//현재 시간 구함
    strftime(stamp, 16, "%Y%m%d_%H%M%S", localtime(&timeStamp));
    std::cout << "[" << stamp << "]";
}

Account::Account(int initial_deposit)
{//계좌 객체 생성될 때마다 정보 출력
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
	_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}//[19920104_091532] index:0;amount:42;created
Account::Account() {}

int	Account::getNbAccounts(void)
{//static 멤버함수도 static 멤버변수처럼 외부 정의 땐 static 떼기
    return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount <<
    ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();//아래서 get~() 써서 static 변수값 가져와도 되긴 함
    std::cout << " account:" << _nbAccounts << ";total:" << _totalAmount <<
    ";deposit" << _totalNbDeposits << ";withdrals:" << _totalNbWithdrawals << std::endl;
}//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

void	Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;
    
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << 
    ";deposit" << deposit << ";amount:" << _amount << ";nb_deposit:" << _nbDeposits << std::endl;
}//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;

    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused\n";
        return false;
    }//[19920104_091532] index:5;p_amount:23;withdrawal:refused
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    ++_nbWithdrawals;
    ++_totalNbWithdrawals;
    std::cout << ";withdrawal:" << withdrawal << ";amount:"
    << _amount << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return true;
}//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

int		Account::checkAmount( void ) const
{
    if (_amount < 0)
        return -1;
    else if (_amount == 0)
        return 0;
    return 1;
}

Account::~Account(void)
{
    --_nbAccounts;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}//[19920104_091532] index:0;amount:47;closed