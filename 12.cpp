#include<iostream>

[[deprecated("Тупая функция щиткодная")]] inline void outCharToInt(char from, char to){
	for(char i=from;i<to;i++)
		std::cout << i <<  ':' << int(i) << std::endl;
}

int main(void){
	/*for(char i='a';i<'z';i++)
		std::cout << i <<  ':' << int(i) << std::endl; // (int) приведет при прикомпиля\
ции, а так по идее иницилизирует лол
	*/
	outCharToInt('a','z');
	outCharToInt('A','Z');
}
