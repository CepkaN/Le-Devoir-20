#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
template<typename T>
void remplir(T bloc[], const int toujours) {
	srand(time(NULL));
	for (int i = 0; i < toujours; i++) 		
		bloc[i] = rand() % 201 - 100;
}
template<typename T>
void show_arr(T bloc[], const int toujours) {
	std::cout << "[ ";
	for (int i = 0; i < toujours; i++)
		std::cout << bloc[i] << ", ";
	std::cout << "\b\b ]\n\n";
}
template<typename T>
int search_index(T bloc[], const int toujours, T valeur, T begin = 0) {
	for (int i = begin; i < toujours; i++)
		if (bloc[i] == valeur)
			return i;
	return -1;
}
template<typename T>
int search_last_index(T bloc[], const int toujours, T valeur, T fin) {
	for (int i = fin; i >= 0; i--)
		if (bloc[i] == valeur)
			return i;
	return -1;
}
template<typename T>
int search_last_index(T bloc[], const int toujours, T valeur) {
	for (int i = toujours - 1; i >= 0; i--)
		if (bloc[i] == valeur)
			return i;
	return -1;
}
void sorin(int num) {
	if (num != -1)
		std::cout << "Индекс : " << num << "\n\n";
	else
		std::cout << "Числа нет в массиве.\n\n";
}
template<typename T>
int arr_min(T bloc[], const int toujours) {
	int min = bloc[0];
	for (int i = 0; i < toujours; i++) 
		min = min < bloc[i] ? min : bloc[i];
	return min;
}
template<typename T>
int arr_max(T bloc[], const int toujours) {
	int max = bloc[0];
	for (int i = 0; i < toujours; i++)
		max = max > bloc[i] ? max : bloc[i];
	return max;
}
template<typename T>
int mean_value(T bloc[], const int toujours) {
	double arif = 0;
	for (int i = 0; i < toujours; i++)
		arif = arif + bloc[i];
	return arif / toujours;
}
template<typename T>
void range(T bloc[], const int toujours,T gauche, T droit) {
	std::cout << "[ ";
	if (gauche > droit)
		std::swap(gauche, droit);
	for (int i = 0; i < toujours; i++) {
		if (bloc[i] >= gauche && bloc[i] <= droit)
			std::cout << bloc[i] << ", ";
	}
	std::cout << "\b\b ]\n\n";
}
template<typename T>
int counter(T bloc[], const int toujours,T nombre) {
	int compte = 0;
	for (int i = 0; i < toujours; i++)
		if (bloc[i] == nombre)
			compte++;
	return compte;
}
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Функции.\n\n ";
	const int cent = 100;
	int mass[cent];
	remplir(mass, cent);
	show_arr(mass, cent);
	std::cout << "Введите значение : ";
	int signe, index, index1;
	std::cin >> signe;
	index = search_index(mass, cent, signe);
	sorin(index);
	index1 = search_last_index(mass, cent, signe);
	sorin(index1);
	std::cout << "Минимальный элемент массива : " << arr_min(mass, cent)<<"\n";
	std::cout << "Максимальный элемент массива : " << arr_max(mass, cent)<<"\n";
	std::cout << "Среднее арифметическое значение элементов массива : " << mean_value(mass, cent) << "\n";
	int G, D;
	std::cout << "\nВведите диапазон : ";
	std::cin >> G >> D;
	std::cout << "Элементы массива в диапазоне от " << G << " до " << D << '\n';
	range(mass, cent, G, D);
	std::cout << "Элемент массива " << signe << " повторяется " << counter(mass, cent, signe) << " раз.\n\n";



	return 0;
}