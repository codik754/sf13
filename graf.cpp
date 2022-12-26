//Файл graf.cpp
#include "graf.h"

#include <list>

//Параметризированный конструктор
Graf::Graf(const std::string& s) {
	count_ = 1;
	v_.push_back(Man(count_, s));
}

//Добавить человека
void Graf::addMan(const string& name) {
	count_++;
	v_.push_back(Man(count_, name));
	l_.push_back(Node(count_));
}

//Создать ребро между вершинами
void Graf::createLink(int n1, int n2) {
	//Заносим записи
	for (auto& a : l_) {
		if (a.number_ == n1) {
			a.addNode(n2);
			break;
		}
	}

	for (auto& a : l_) {
		if (a.number_ == n2) {
			a.addNode(n1);
			break;
		}
	}
}

//Создать ребро между вершинами
void Graf::createLink(const string& s1, const string& s2) {
	int n1 = 0;
	int n2 = 0;
	
	//Ищем номера
	for (auto& a : v_) {
		if (a.name_ == s1) {
			n1 = a.number_;
			break;
		}
	}
	for (auto& a : v_) {
		if (a.name_ == s2) {
			n2 = a.number_;
			break;
		}
	}

	//Заносим записи
	for (auto& a : l_) {
		if (a.number_ == n1) {
			a.addNode(n2);
			break;
		}
	}
	for (auto& a : l_) {
		if (a.number_ == n2) {
			a.addNode(n1);
			break;
		}
	}
}

//Проверка есть ли связь между вершинами
bool Graf::checkLink(int n1, int n2) {
	Node* node = nullptr;
	//Ищем нужный узел в  векторе
	for (auto& a : l_) {
		if (a.number_ == n1) {
			node = &a;
			break;
		}
	}

	//Проверяем связь
	if (node) {
		for (auto& a : node->link_) {
			if (a == n2) {
				return true;
			}
		}
	}

	return false;
}

//Получить имя по номеру вершины
string Graf::getName(int n) const {
	for (auto& a : v_) {
		if (a.number_ == n) {
			return a.name_;
		}
	}
	return "UNKNOWN";
}

//Получить указатель на вершину по номеру
Node* Graf::getNode(int n) {
	for (auto& a : l_) {
		if (a.number_ == n) {
			return &a;
		}
	}

	return nullptr;
}

//Алгоритм поиска друзей через 3 купожатия
void Graf::thisIsAlgorithm() {
	cout << "One handshake: " << endl;

	size_t l = v_.size();

	//Ищем друзей с одним рукопожатием
	//Обходим список смежных вершин
	for (auto& a : l_) {
		//Обходим по вектору номеров смежных вершин
		for (auto& a1 : a.link_) {
			if (a1 < a.number_) {
				continue;
			}
			//Выводим значение
			cout << getName(a.number_) << " with " << getName(a1) << "   ";
		}
	}
	cout << endl;

	//Ищем друзей с двумя рукопожатиями
	cout << endl << "Two handshake: " << endl;
	//Обходим список смежных вершин
	for (auto& a : l_) {
		//Обходим по вектору номеров смежных вершин
		Node* cur = &a;
		for (auto a1 : a.link_) {
			int i = 1;
			while (i < 2) {
				cur = getNode(a1);
				++i;
			}
			for (auto a2 : cur->link_) {
				if (a2 < a.number_) {
					continue;
				}
				if (a2 == a.number_) {
					continue;
				}
				//Выводим значение
				cout << getName(a.number_) << " with " << getName(a2) << "   ";
			}
		}
		
	}
	cout << endl;

	//Ищем друзей с тремя рукопожатиями
	cout << endl << "Three handshake: " << endl;
	//Обходим список смежных вершин
	for (auto& a : l_) {
		//Обходим по вектору номеров смежных вершин
		Node* cur = &a;
		Node* cur1 = &a;
		for (auto a1 : a.link_) {
			int i = 1;
			while (i < 2) {
				cur = getNode(a1);
				++i;
			}
			for (auto a2 : cur->link_) {
				int i1 = 1;
				while (i1 < 2) {
					cur1 = getNode(a2);
					++i1;
				}
				for (auto a3 : cur1->link_) {
					if (a3 < a.number_) {
						continue;
					}
					if (a3 == a.number_) {
						continue;
					}
					//Выводим значение
					if (a3 - a.number_ == 3) {
						cout << getName(a.number_) << " with " << getName(a3) << "   ";
					}
				}
			
			}
		}
	}
	cout << endl;
	
}