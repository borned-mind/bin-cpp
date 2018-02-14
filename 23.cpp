#include"23.hpp"
#include<iostream>
#include<vector>

#define CINERR if(!std::cin) throw( std::runtime_error("ERROR: read lval with kind") );

void Token_Stream::putback(char kind, double val){
	buffer = {kind,val};
}
void Token_Stream::putback(char kind){
	buffer.kind=kind;
}
void Token_Stream::putback(double val){
	buffer.val=val;
}
void Token_Stream::putback(Token t){
	buffer=t;
}
Token Token_Stream::get(void){
	if(full)
		return this->buffer;
	char kind, tmp;
	double val=0;
	do{
		 tmp = std::cin.peek();
		 switch(tmp){
			case '+': case '-':
			case '*': case '/': 
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


void parser::primary(double & res, Token &last){
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

}




double parser::expression(){
	Token t=get_token();
	Token t2;
	/*static*/ double res=0;
	bool isExpression=true;



	while(isExpression){
		//std::cout << t.val << ":" << t.kind << std::endl;
		//std::cout << t2.val << ":" << t2.kind << std::endl;
		switch(t.kind){
			case '+':	
				t2 = get_token();						
				res += t2.val;
				break;			
			case '-':
				//if(!res)
				t2 = get_token();
				res -= t2.val;
				break;
			case '*':
			case '/':
				primary(res, t);
				continue;
				break;
			case 'x':
			case ';':
				return res;
				break;
			case 'n':
				if(res == 0)
					res = t.val;
				break;
			default:
			//	std::cin.putback(t.kind);
			//	std::cin.putback(t.val);
				isExpression=false;
				break;
		}
		t=get_token();
	}
	return res;
}

Token parser::get_token(){
	Token_Stream tmp;
	return tmp.get();
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
