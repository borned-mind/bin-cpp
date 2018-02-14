#include<iostream>

double ctok(double x){
	return x*273.15;
}

int main(void){
	double c;
	std::cin>>c;
	double k = ctok(c);
	k <= -273.15 ? std::cout << "ОШИБКА: температура ниже -273.15C" << std::endl :
	std::cout << k << std::endl;
	//std::cout << ctok(c) << std::endl;
}
