#include "Contact.hpp"

Contact::Contact() {}

std::string Contact::GetFirstName(void) const
{
    return mFirstName;
}
std::string Contact::GetLastName() const
{
    return mLastName;
}
std::string Contact::GetNickName() const
{
    return mNickName;
}
std::string Contact::GetPhoneNumber() const
{
    return mPhoneNumber;
}
std::string Contact::GetDarkestSecret() const
{
    return mDarkestSecret;
}

void Contact::SetFirstName(std::string s)
{
    mFirstName = s;
}
void Contact::SetLastName(std::string s)
{
    mLastName = s;
}
void Contact::SetNickName(std::string s)
{
    mNickName = s;
}
void Contact::SetPhoneNumber(std::string s)
{
    mPhoneNumber = s;
}
void Contact::SetDarkestSecret(std::string s)
{
    mDarkestSecret = s;
}

/*
Contact::Contact(const Contact& ref)
{
    mFirstName = ref.getFirstName();
    mLastName = ref.getLastName();
    mNickName = ref.getNickName();
    mPhoneNumber = ref.getPhoneNumber();
    mDarkestSecret = ref.getDarkestSecret();
}
*/