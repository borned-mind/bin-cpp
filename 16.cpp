#include<iostream>
#include<vector>

template <typename T>
void sort(std::vector<T> v){
	for(unsigned int i =2;i--;)
	for(T i=1;i!=v[v.size()-1];i++){
		if(v[i-1] > v[i]){
			T tmp = v[i-1];
			v[i] = v[i-1];
			v[i-1]=v[i];
		}
	}
}

int main(void){
	std::vector<double> list;
	char ch;
	while(ch != 'n'){
		static double tmp = 0.0;
		std::cin >> tmp;
		list.push_back(tmp);
		std::cout << "Continue(n/any)" << std::endl;
		std::cin>>ch;
	}
	sort(list);
	std::cout << "Медиана: " << list[list.size()/2] << std::endl;
}
