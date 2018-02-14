#include<iostream>
#include<vector>
#include<string>



template <typename T>
void sort(std::vector<T> & v){
	for(auto i = 0;i<v.size();i++){
		if(v[i] < v[i-1])  {
			auto tmp = v[i];
			v[i] = v[i-1];
			v[i-1]=tmp;
		}
	}
}

inline int min(int a,int b){
	if(a > b)
		return b;
	return a;
}

inline int max(int a, int b){
	if( min(a,b) == a ) return b;
	return a;
}

inline int abs(int x){
	return x > 0 ? x : -x;
}

int main(void){
	std::vector<double> v;
	std::string type;
	double min=999999.9,max;
	while(type != "|"){
			static double tmp;
			std::cin >> tmp >> type;
			for(auto x : v) 
				if(x == tmp) tmp = 0;
			if(!tmp){
				std::cout << "Существует или равно 0" << std::endl;
				 continue;
			}

			if(type == "cm"){
				tmp/=100;
			}else if(type=="in") tmp *=2.54;
			else if(type != "m"){
				std::cout << "неизвестный тип" << std::endl;
				continue;
			}

			v.push_back(tmp);
			for(auto x : v){
				if(x < min) min = x;
				else if(x > max) max = x; 
			}
		if(min == v[v.size()-1]) std::cout << "Наименьшее из всех веденных\n";
		else if(max == v[v.size()-1]) std::cout << "Наибольшее из всех веденных\n";
		std::cout << "Добавленно" << std::endl;
	}
	sort(v);
	std::cout << "Наименьшее -> " << min << " наиб " << max << std::endl;
	std::cout << "колл-во: " << v.size() << std::endl;
	double sum;
	for(auto x : v) sum+=x;
	std::cout << "Сумма: " << sum;
}
