//Файл node.h
#pragma once
#include <vector>

using std::vector;

//Узел для записи в список смежности
struct Node {
	int number_; //номер элемента
	vector<int> link_;//смежные с ним элементы

	//Конструктор по умолчанию
	Node() : number_(0), link_() {}
	//Параметризированный конструктор
	Node(int n) : number_(n), link_() {}
	//Консруктор копирования
	Node(const Node& other) : number_(other.number_), link_(other.link_) {}
	//Деструктор
	~Node() = default;
	//Оперетор присваивания
	Node& operator = (const Node& other);
	
	//Добавить номер смежной вершины
	void addNode(int n);
};