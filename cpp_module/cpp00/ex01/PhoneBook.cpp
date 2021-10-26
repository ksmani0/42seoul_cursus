#include "PhoneBook.hpp"

int PhoneBook::mNum = 0;

PhoneBook::PhoneBook() : mIndex(0) {}

void PhoneBook::AddList(void)
{
    std::string temp;

    std::cout << "Input first name: ";
    std::cin >> temp; mList[mIndex].SetFirstName(temp);
    std::cout << "Input last name: ";
    std::cin >> temp; mList[mIndex].SetLastName(temp);
    std::cout << "Input nick name: ";
    std::cin >> temp; mList[mIndex].SetNickName(temp);
    std::cout << "Input phone numbers: ";
    std::cin >> temp; mList[mIndex].SetPhoneNumber(temp);
    std::cout << "Input darkest secret: ";
    std::cin >> temp; mList[mIndex].SetDarkestSecret(temp);

    mIndex = (mIndex + 1) != 8 ? mIndex + 1 : 0;
    mNum = mNum != 8 ? mNum + 1 : mNum;
}

void PhoneBook::PrintListDigit(const std::string s, bool isEnd) const
{
    if (s.length() <= 10)
        std::cout << std::setw(10) << s;
    else
    {
        for (int i = 0; i < 9; ++i)
            std::cout << s[i];
        std::cout << '.';
    }
    if (isEnd == true)
        std::cout << "\n";
    else
        std::cout << "|";
}

void PhoneBook::ShowAllList(void) const
{
    std::cout << "   index  |first name| last name| nickname \n";
    std::cout << "---------- ---------- ---------- ----------\n";

    for (int i = 0; i < mNum; ++i)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        PrintListDigit(mList[i].GetFirstName(), false);
        PrintListDigit(mList[i].GetLastName(), false);
        PrintListDigit(mList[i].GetNickName(), true);
    }
    std::cout << "---------- ---------- ---------- ----------\n";
}

void PhoneBook::ShowOneContact(void) const
{
    int idx;
    std::cout << "\nEnter the index of the contact you want to search: ";
    std::cin >> idx;

    if (std::cin.fail())//문자 등 비정상 입력 들어오면 잡음
    {        
        std::cin.clear();//failbit 초기화해서 정상 작동하게 해줌
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//입력 버퍼의 문자를 읽어와 버림
        std::cout << "Wrong input! Please enter a number.\n";
        return;
    }
    else if (idx < 1 || idx > mNum)
    {
        std::cout << "Wrong index!\n";
        return;
    }
    std::cout << "First name: " << mList[idx - 1].GetFirstName() << std::endl;
    std::cout << "Last name: " << mList[idx - 1].GetLastName() << std::endl;
    std::cout << "Nickname: " << mList[idx - 1].GetNickName() << std::endl;
    std::cout << "Phone number: " << mList[idx - 1].GetPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << mList[idx - 1].GetDarkestSecret() << std::endl;
}