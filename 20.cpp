#include<iostream>
#include<vector>
#include<type_traits>
// run-time checked narrowing cast (type conversion):
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) throw ( std::runtime_error("info loss"));
	return r;
}


int main(void){
	std::vector<int> v;
	int sum,count;
	std::cout << "Введите кол-во суммируемых значений:";
	std::cin >> count;
	std::cout << "Введите несколько целых чисел: ";
	for(int i;std::cin>>i;)
		v.push_back(i);
	//if(!std::cin);

	if( count > v.size() ) {
		std::cerr << "Больше чем есть" << std::endl;
		return 1;
	}

	for(auto x : v){
		try{
			sum=narrow_cast<int>(sum+x);
		}
		catch(...){
			std::cout << "Не может быть предоставленно в виде int" << std::endl;
		}
		std::cout << x << " ";
	}

	std::cout << std::endl << "Сумма: " << sum << std::endl;
}
