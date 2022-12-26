//Файл node.cpp
#include "node.h"
#include <iostream>

using std::endl;
using std::cout;

//Оперетор присваивания
Node& Node::operator = (const Node& other) {
	//Проверка на самоприсвоение
	if (&other == this) {
		return *this;
	}
	number_ = other.number_;
	link_ = other.link_;
	return *this;
}

//Добавить номер смежной вершины
void Node::addNode(int n) {
	for (auto& a : link_) {
		if (a == n) {
			cout << "Error. " << n << " in " << number_ << " already exists." << endl;
			return;
		}
	}
	link_.push_back(n);
}