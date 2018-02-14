#include<iostream>
#include<string>

int main(void){
	std::string name;
	int age;
	std::cout << "Ваше имя и возраст: ";
	std::cin >> name >> age ;
	std::cout << name << " ваш возраст в месяцах:" << age*12 << std::endl;

}
