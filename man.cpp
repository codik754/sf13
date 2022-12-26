//Файл man.cpp
#include "man.h"

//Оператор присваивания
Man& Man::operator = (const Man& other) {
	//Проверка на самоприсвоение
	if (&other == this) {
		return *this;
	}

	number_ = other.number_;
	name_ = other.name_;

	return *this;
}