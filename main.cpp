//Файл main.cpp
#include <iostream>
#include "graf.h"

using std::cout;
using std::endl;

int main() {
	Graf G;//Создаем граф
	//Добавляем людей
	G.addMan("Oleg");
	G.addMan("Nikita");
	G.addMan("Nasty");
	G.addMan("Vany");
	G.addMan("Geny");
	//Организуем связи
	G.createLink("Oleg", "Nikita");
	G.createLink("Nasty", "Nikita");
	G.createLink("Nasty", "Vany");
	G.createLink("Geny", "Vany");

	//Запускаем алгоритм
	G.thisIsAlgorithm();

	return 0;
}