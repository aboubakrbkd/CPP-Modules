#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <exception>


#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        class GradeTooHighExeption : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooLowExecption : public std::exception {
            public:
                const char *what() const throw();
        };
        int getGrade() const ;
        std::string getName() const;
        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif