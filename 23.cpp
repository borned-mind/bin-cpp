#include"23.hpp"
#include<iostream>


#define CINERR if(!std::cin) throw( std::runtime_error("ERROR: read lval with kind") );

void Token_Stream::putback(char kind, double val){
	buffer.push_back ( Token{kind,val} );
}
void Token_Stream::putback(char kind){
	buffer.push_back ( Token{kind, 0} );
}
void Token_Stream::putback(double val){
	buffer.push_back ( Token{'n', val} );
}
void Token_Stream::putback(Token t){
	buffer.push_back ( t );
}

void Token_Stream::getline(void){
	Token t;
	while( (t = get()).kind != ';' )
		putback(t.kind,t.val);
	putback(';');
}

Token Token_Stream::get(void){

	char kind, tmp;
	double val=0;
	do{
		 tmp = std::cin.peek();
		 switch(tmp){
			case '+': case '-':
			case '*': case '/':
			case '!': 
			case ';': 
				std::cin.get();
				return Token( tmp , 0 );
				break;
			case ' ':
				std::cin.get();
				break;
			default:
				break;
		 } 
	}while(tmp == ' ');	
	
	std::cin >> val;
	if(!std::cin){
		std::cin.clear();
		kind=tmp;
		return Token(kind,0);
	}	
	return Token('n', val);
//	char kind = std::cin.get();
}


void parser::primary( double & res ){
/*
	Token t=last, t1;

	while(t.kind == '*' || t.kind == '/'){
		switch(t.kind){
			case '*':
				t1=get_token();
				res*=t1.val;
				break;
			case '/':
				t1=get_token();
				if(t1.val == 0 || res == 0)
					throw( std::runtime_error( "Dividing on zero" ) );
				res/=t1.val;
				break;
		}
		t=get_token();
	}
	last=t;
*/
}


long long int parser::factorial(long long int to){
	if(to == 0) return 1;
	return to * factorial(to-1);
}

double parser::expression(){
	std::vector<Token> tokens = get_token();
	/*static*/ double res=0;
	auto it = tokens.begin();	
	for(it;it != tokens.end();it++) {
		//std::cout << t.val << ":" << t.kind << std::endl;
		//std::cout << t2.val << ":" << t2.kind << std::endl;
		switch( (*it).kind){
			case '+':	

				res += (it+1)->val;
				break;			
			case '-':
				//if(!res)
				res -= (it+1)->val;
				break;
			case '*':
			case '/':
				primary(res);
				continue;
				break;
			case '!':
				//res += factorial(get_token().val);
				res = factorial( (it+1)->val );
				break;
			case 'x':
			case ';':
				return res;
				break;
			case 'n':
				if(res == 0)
					res = it->val;
				break;
			default:	
				break;
		}

	}
	return res;
}

std::vector<Token> parser::get_token(){
	Token_Stream tmp;
	tmp.getline();
	return tmp.get_buffer();
}



int main(void){
	try{
		parser pars;
		while(1){
			std::cout << "> " << pars.expression() << std::endl;
		}
	}catch(std::runtime_error e ){
		std::cerr << "Runtime Error: " <<  e.what() << std::endl;
		return 1;
	}
	catch(...){}	
}
