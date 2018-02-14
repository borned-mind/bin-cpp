#include<iostream>
#include <signal.h>

void sigfpu(int i){
	std::cout << "На ноль делить нельзя("<<i<<")" << std::endl;
	exit(-1);
}

int main(void){
	signal(SIGFPE, sigfpu);
	char ch;
	int lval, rval;
	std::cin >> ch >> lval >> rval;
	switch(ch){
		case '+':
			std::cout << lval+rval;
			break;
		case '-':
			std::cout << lval-rval;
			break;
		case '/':
			std::cout<< lval/rval;
			break;
		case '*':
			std::cout << lval*rval;
			break;
		default:
			std::cout << "uknown operation" << std::endl;
			break;
	}
	std::cout << std::endl;
}
