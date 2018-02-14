#include<iostream>


	constexpr float get_one_mile(void){
		return 1.609;
	}



int main(void){
	double miles;
	std::cout << "Введите колл-во миль: ";
	std::cin >> miles;
	std::cout << "Киллометров: " << miles*get_one_mile() << std::endl;
}
