#include<iostream>
#include<math.h>


//Предисловия: функция quadSqrt принимает в себя значения квадратного уравнения
// тот самый а, b, c и x в виде контейнера, массива с двумя значениями double

#define SQRT(type,a,D) -b type sqrt(D)/2*a

void quadSqrt(double a, double b, double c, double (&arr)[2]){
	double D = (b*b) - 4*a*c;
//	std::cout << D << ":" << b << std::endl;
	if(D < 0) throw( std::runtime_error("Решение имеет только копмплексное число") );
	arr[0]= SQRT(+,a,D);
	arr[1]=SQRT(-,a,D);
}

int main(void){
	try{
		double a,b,c;
		std::cin >> a >> b >> c;
		double sqrts[2];
		quadSqrt(a,b,c,sqrts);
		std::cout << "x1=" << sqrts[0] << ":x2=" << sqrts[1] << std::endl;
	}catch(std::runtime_error & e){ std::cerr << e.what() << std::endl;}
	catch(...){}
}
