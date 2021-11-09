#include "Character.hpp"

Character::Character(void) : mName("")
{
    for (int i = 0; i < 4; ++i)
        mInventory[i] = NULL;//일단 NULL 초기화
}
Character::Character(std::string name) : mName(name)
{
    for (int i = 0; i < 4; ++i)
        mInventory[i] = NULL;
}
Character::Character(const Character& ref)
: mName(ref.mName)
{
    for (int i = 0; i < 4; ++i)
    {
        if (ref.mInventory[i] != NULL)
            mInventory[i] = ref.mInventory[i]->clone();
        else
            mInventory[i] = NULL;
    }
}

//////////

Character& Character::operator=(const Character& ref)
{
    mName = ref.mName;
    for (int i = 0; i < 4; ++i)
    {
        delete mInventory[i];
        if (ref.mInventory[i] != NULL)
            mInventory[i] = ref.mInventory[i]->clone();
        else//ref 인벤토리가 덜 차있을 수 있으니 원본의 넘는 부분은 해제
            mInventory[i] = NULL;
    }

    return *this;
}
const std::string& Character::getName(void) const
{
    return mName;
}
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (mInventory[i] == NULL)
        {
            mInventory[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
		return;
    if (mInventory[idx] != NULL)
    	mInventory[idx]->SetType("");
}//지우지 말라고 했으니...
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
		return;
	if (mInventory[idx] != NULL)//Cure 또는 Ice의 use() 호출
		mInventory[idx]->use(target);
}

//////////

Character::~Character(void)
{
    for (int i = 0; i < 4; ++i)
        delete mInventory[i];
}