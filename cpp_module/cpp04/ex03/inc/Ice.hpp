#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();	
	Ice(const Ice& ref);

	Ice& operator=(const Ice& ref);
	AMateria* clone() const;
	void use(ICharacter& target);
	std::string GetType() const;
	void SetType(std::string type);

    ~Ice();
};

#endif