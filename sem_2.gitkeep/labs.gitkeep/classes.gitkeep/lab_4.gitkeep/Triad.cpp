#include "Triad.h"
//конструктор без параметров 
Triad::Triad(void) {
	first = 0;
	second = 0;
	third = 0;
}
//деструктор
Triad::~Triad(void) {}
//конструктор с параметрами
Triad::Triad(int F, int S, int T) {
	first = F;
	second = S;
	third = T;
}
//конструктор копирования 
Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
//модификаторы
void Triad::setSecond(int S) {
	second = S;
}
void Triad::setFirst(int F) {
	first = F;
}
void Triad::setThird(int T) {
	third = T;
}
//перегрузка операции присваивания 
Triad& Triad::operator=(const Triad& T) {
	if (&T == this) return *this;
	first = T.first;
	second = T.second;
	third = T.third;
	return *this;
}
//глобальная функция для ввода
istream& operator<<(istream& in, Triad& T) {
	cout << "\nFIRST:"; in>> T.first;
	cout << "\nSECOND:"; in >> T.second;
	cout << "\nTHIRD:"; in >> T.third;
	return in;
}
//глобальная функция для вывода 
ostream& operator<<(ostream& out, const Triad& T) {
	out << "\nFIRST:" << T.first;
	out << "\nSECOND:" << T.second;
	out << "\nTHIRD:" << T.third;
	out << "\n";
	return out;
}