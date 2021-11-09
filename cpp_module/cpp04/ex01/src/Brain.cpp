#include "Brain.hpp"

Brain::Brain(void) : num(0) {}
Brain::Brain(const Brain& ref) : num(ref.num)
{
    for (unsigned int i = 0; i < ref.num; ++i)
        ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain& ref)
{
    for (unsigned int i = 0; i < ref.num; ++i)
        ideas[i] = ref.ideas[i];
    num = ref.num;

    return *this;
}

bool Brain::AddIdea(std::string idea)
{
    if (num == 100)
    {
        std::cout << "My head already full!\n";
        return false;
    }
    this->ideas[num] = idea;
    ++num;
    return true;
}

const std::string& Brain::GetIdea(unsigned int idx) const
{//함수가 const고 반환값이 참조자니 반환값도 변경할 수 없게 const 걸기
    return ideas[idx];
}

Brain::~Brain(void) {}