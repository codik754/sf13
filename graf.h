//Файл graf.h
#pragma once
#include <iostream>
#include <vector>
#include "man.h"
#include "node.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Graf{
	int count_; //количество вершин
	vector<Man> v_;//вектор с вершинами
	vector<Node> l_;//вектор со списком вершины и со смежными с ним вершинами
public:
	//Конструктор по умолчанию
	Graf() : count_(0), v_() {}
	//Параметризированный конструктор
	Graf(const std::string& s);
	//Деструтктор
	~Graf() = default;
	//Добавить человека
	void addMan(const string &name);
	//Создать ребро между вершинами
	void createLink(int n1, int n2);
	//Создать ребро между вершинами
	void createLink(const string &s1, const string &s2);
	//Проверка есть ли связь между вершинами
	bool checkLink(int n1, int n2) ;
	//Получить имя по номеру вершины
	string getName(int n) const;
	//Получить указатель на вершину по номеру
	Node* getNode(int n);
	//Алгоритм поиска друзей через 3 рукопожатия
	void thisIsAlgorithm();
};

