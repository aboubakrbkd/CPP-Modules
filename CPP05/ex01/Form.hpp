#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Form {
    private:
        const std::string name;
        bool is_signed;
        const int sign_grade;
        const int execute_grade;
    public:
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        Form();
        ~Form();
        Form(const Form& obj);
        Form& operator=(const Form& obj);
        std::string getName() const;
        bool getIs_Signed() const;
        int  GetSign_Grade() const;
        int  Get_Execute_grade() const;
        void beSigned(Bureaucrat &sign);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif