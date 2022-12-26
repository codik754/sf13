//Файл man.h
#pragma once
#include <string>

using std::string;

struct Man {
	int number_; //номер вершины
	string name_;//имя человека

	//Конструктор по умолчанию
	Man() : number_(0), name_("UNKNOWN") {}
	//Параметризированный конструктор
	Man(int n, const string &s) : number_(n), name_(s) {}
	//Конструктор копирования
	Man(const Man& other) : number_(other.number_), name_(other.name_) {}
	//Деструктор
	~Man() = default;
	//Оператор присваивания
	Man& operator = (const Man& other);
};