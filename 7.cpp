#include<iostream>

inline static int min(int a, int b){
	if(a > b)
		return b;
	else if(b > a)
		return a;
}

inline static int max(int a, int b){
	int tmp{ min(a,b) };
	if( tmp == a) return b;
	else if( tmp == b) return a;
}

//globals
static std::string min_num, middle_num, max_num;

template<typename T> void sort(T arg){
	if(arg > max_num) max_num = arg;
	else if(arg < min_num) min_num = arg;
	else if ( arg != min_num && arg != max_num) middle_num = arg;
}

void sorting() {}
template <typename T, typename ... Args > void sorting(T arg, Args ... args){
	sort(arg);
	sorting(args...);
} 

int main(void){
	std::cout << "Введите три фразы: ";
	std::string a,b,c;
	std::cin >> a >> b >> c;
	min_num = a;
	middle_num = b;
	max_num = c;
	sorting(a,b,c);
	sorting(a, b ,c);
	std::cout << min_num << ", "<< middle_num << ", " << max_num << std::endl;

}
