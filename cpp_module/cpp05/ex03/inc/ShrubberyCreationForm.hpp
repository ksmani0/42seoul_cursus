#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{//sign 145, exec 137
public://매개변수 하나만 받는 생성자만 명시됨
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
    void execute(Bureaucrat const & executor) const;
    ~ShrubberyCreationForm();

private:
    std::string mTarget;
};

#define SHRUBBERY "\
              * *\n\
           *    *  *\n\
      *  *    *     *  *\n\
     *     *    *  *    *\n\
 * *   *    *    *    *   *\n\
 *     *  *    * * .#  *   *\n\
 *   *     * #.  .# *   *\n\
  *     *#.  #: #* * *    *\n\
 *   * * *#. ##*       *\n\
   *        ###\n\
             ##\n\
             ##.\n\
             .##:\n\
             :###\n\
             ;###\n\
            ,####.\n\
///////////.######.////////"

#endif