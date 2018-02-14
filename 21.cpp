#include<iostream>
// run-time checked narrowing cast (type conversion):
template<class R, class A> R narrow_cast(const A& a)
{
        R r = R(a);
        if (A(r)!=a) throw ( std::runtime_error("info loss"));
        return r;
}
int fibonachi(int to){
	int a=0,b=1,tmp=0;
	for(to;to--;){
		//if( b > 1<<sizeof(int) ) 
		if(a < 0 || b < 0) throw( std::runtime_error("<0") );
		tmp={b};
		b=narrow_cast<int>(a+b);
		a=tmp;
		std::cout << tmp << std::endl;
	}
	return b;
}

int main(void){
	int j;
	while(1){
		try{
			std::cout << fibonachi(++j) << std::endl;
		}catch(...){
			std::cerr<<"Ошибка, число " << j << " является максимальным для типа int" << std::endl;
			return 1;
		}
	}
}
