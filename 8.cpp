#include<iostream>



int main(void){
	int num;
	std::cout << "Введите число: " << std::endl;
	std::cin >> num;
	std::cout << "Число " << num << (num%2 == 1 ? " не является" : " является") << " четным" << std::endl;
}
