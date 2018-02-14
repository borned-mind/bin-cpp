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

void Token_Stream::setPriority(void){
	std::vector<Token> withPrior;
	Grammar::priority last = Grammar::priority::high;
	while((char)last){
		std::vector<char> kinds;	

		for(auto x : Grammar::priority_vals)
			if(x.prior==last) 
				kinds.push_back(x.kind);
/*
		for(auto x : kinds){
				std::cout << x << std::endl;
				//std::cout << int(x.prior) << ":" << x.kind << std::endl;
		}
		std::cout << "~~~~~" << std::endl;
*/	

			for( auto it = std::begin(buffer); it != std::end(buffer); it++ ){
				for(char lastKind=0;lastKind != kinds.size();lastKind++)
					if( it->kind == kinds[ (int)lastKind ] )
						for(int i = -1;i != 1; i++)
						 if( (it+i)->kind  )
						 {
						  if( i < 0 && (it)->kind == 'n') continue;
						  withPrior.push_back( *(it+i) );	
						  //buffer.erase ( it+i );						
						 }
			}

		last = (Grammar::priority)((char)last-1);
	}
	//withPrior.erase( std::end(withPrior) ); // from buggy version, not need
	//for(auto x : withPrior)\
		std::cout << x.val << ":" << x.kind << std::endl; // for debuging, not need
	buffer = withPrior;
}

void Token_Stream::getline(void){
	Token t;
	while( (t = get()).kind != ';' )
		putback(t.kind,t.val);
	putback(';');
	setPriority();
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


void parser::primary( double & res , std::vector<Token>::const_iterator& it, std::vector<Token>::const_iterator end  ){

	for(it;it->kind == '*' || it->kind == '/';it++) {
		switch( (*it).kind){
			case '*':
				res*=(it+1)->val;
				break;
			case '/':
				if((it+1)->val == 0 || res == 0) 
					throw( std::runtime_error( "Dividing on zero" ) );
				res/=(it+1)->val;
				break;
			}
	}
}


long long int parser::factorial(long long int to){
	if(to == 0) return 1;
	return to * factorial(to-1);
}

double parser::expression(){
	std::vector<Token> tokens = get_token();
	/*static*/ double res=0;	
	for(auto it = tokens.cbegin();it != tokens.cend();it++) {
		//std::cout << t.val << ":" << t.kind << std::endl;
		//std::cout << t2.val << ":" << t2.kind << std::endl;
		switch( (*it).kind){
			case '+':	
				res += (it+1)->val;
				break;			
			case '-':
				res -= (it+1)->val;
				break;
			case '*':
			case '/':
				primary(res, it, tokens.cend());
				continue;
				break;
			case '!':
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
