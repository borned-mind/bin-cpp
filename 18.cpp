#include<iostream>


double ctok(double x){
	if(x<=-273.15) throw( std::runtime_error("ОШИБКА: Температура ниже или равна -273.15") );
	return x/273.15;
}

int main(void){
	double c;
	std::cin>>c;
	try{
		std::cout << ctok(c) << std::endl;
	}catch(std::runtime_error & e){
		std::cerr << e.what() << std::endl;
	}
	//k <= -273.15 ? std::cout << "ОШИБКА: температура ниже -273.15C" << std::endl :
	//std::cout << k << std::endl;
	//std::cout << ctok(c) << std::endl;
}
