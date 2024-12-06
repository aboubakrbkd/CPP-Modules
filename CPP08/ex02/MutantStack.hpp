#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
	private:
		MutantStack(const MutantStack& obj) {(void) obj;};
		MutantStack& operator=(const MutantStack& obj) {(void) obj;};
	public:
		MutantStack() {};
		~MutantStack() {};

		typedef typename std::stack<T, std::deque<T> >::container_type::iterator iterator;
		typedef typename std::stack<T, std::deque<T> >::container_type::const_iterator const_iterator;

		iterator begin(){
			return (this->c.begin());
		}
		const_iterator begin() const{
			return (this->c.begin());
		}
		const_iterator end() const {
			return (this->c.end());
		}
		iterator end() {
			return (this->c.end());
		}

};

#endif