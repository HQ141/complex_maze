#ifndef DYNAMIC_SAFE_ARRAY_H
#define	DYNAMIC_SAFE_ARRAY_H
#include<iostream>
#include<stdarg.h>
using namespace std;
template<class T,int cap=0>
class DSA {
private:
	int size;
	T* ptr;
public:
	DSA() {
		size = 0;
		ptr = NULL;
		if (cap) {
			inc_size(cap);
		}
	}
	DSA(int a) :
		size(a) {
		ptr = new T[a];
		for (int i = 0; i < size; i++) {
			ptr[i] = 0;
		}
	}
	int get_size() { return size; }
	~DSA(){
		delete[]ptr;
	}

	DSA(T num,T,...) {
		size = cap;
		ptr = new T[size];
		for (int i =0; i <cap ; i++) {
			ptr[i] = *(&num + i);
		}
	}
	DSA& operator=(const DSA& a) {
		size = a.size;
		ptr = new T[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = a.ptr[i];
		}
		return *this;
	}
	void push(T &a) {
		if (size == 0) {
			size = 1;
			ptr = new T[size];
			ptr[0] = a;
		}
		else {
			inc_size(1);
			ptr[get_size() - 1] = a;
		}
	}
	void inc_size(int a) {
		T* temp = new T[size+a];
		for (int i = 0; i < size+a; i++) {
			if (i < size)
				temp[i] = ptr[i];
			else
				temp[i] = 0;
		}
		size = size + a;
		delete[] ptr;
		ptr = temp;
	}
	T& operator[](int i) {
		if (i >= 0 && i < size)
			return *(ptr+i);
		cout << "ERROR" << endl;
		exit(0);
	}
};

#endif // !DYNAMIC_SAFE_ARRAY_H