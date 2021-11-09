#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        mInventory[i] = 0;//일단 NULL 초기화
}
MateriaSource::MateriaSource(const MateriaSource& ref)
{
    for (int i = 0; i < 4; ++i)
    {
        if (ref.mInventory[i] != NULL)
            mInventory[i] = ref.mInventory[i]->clone();
        else
            mInventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& ref)
{
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
void MateriaSource::learnMateria(AMateria* m)
{//Character의 equip()와 같음
    for (int i = 0; i < 4; ++i)
    {
        if (mInventory[i] == NULL)
        {
            mInventory[i] = m;
            return;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (mInventory[i] != NULL && mInventory[i]->GetType() == type)
            return mInventory[i]->clone();
    }
    return NULL;//일치하는 type 없을 때
}

AMateria* MateriaSource::GetAInventory(unsigned int idx) const
{
    return mInventory[idx];
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        delete mInventory[i];
}
