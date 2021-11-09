#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain& ref);

    Brain& operator=(const Brain& ref);
    bool AddIdea(std::string idea);
    const std::string& GetIdea(unsigned int idx) const;
    ~Brain();

private:
    std::string ideas[100];
    unsigned int num;
};

#endif