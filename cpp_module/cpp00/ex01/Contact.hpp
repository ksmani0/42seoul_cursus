#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cstring>

class Contact
{
public:
    Contact();// Contact 객체 배열을 위한 생성자
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickName() const;
    std::string GetPhoneNumber() const;
    std::string GetDarkestSecret() const;
    void SetFirstName(std::string s);
    void SetLastName(std::string s);
    void SetNickName(std::string s);
    void SetPhoneNumber(std::string s);
    void SetDarkestSecret(std::string s);

private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickName;
    std::string mPhoneNumber;
    std::string mDarkestSecret;
};

#endif