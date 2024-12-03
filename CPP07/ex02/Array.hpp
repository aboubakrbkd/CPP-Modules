#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T>
class Array {
	private:
		T	*arr;
		unsigned int	len;
	public:
		Array() : arr(NULL), len(0) {};
		~Array() {
			delete[] arr;
		};
		Array(unsigned int n) {
			arr = new T[n]();
			len = n;
		};
		Array(const Array &obj) {
			arr = new T[obj.len];
			len = obj.len;
			for (unsigned int i = 0; i < len; i++)
				arr[i] = obj.arr[i];
		};
		Array& operator=(const Array& obj) {
			if (*this != &obj)
			{
				delete[]arr;
				len = obj.len;
				arr = new T[len];
				for (int i = 0; i < len; i++)
					arr[i] = obj.arr[i];
			}
			return *this;
		};
		unsigned int size() const{
			return len;
		};
		T& operator[](unsigned int i) {
			if (i >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[i];
		};
};


#endif