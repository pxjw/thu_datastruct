#include <iostream>
int main() {
	// your code goes here
	double a,c,res;
	char b;
	std::cin>>a>>b>>c;
	switch(b){
		case '+':res = a+c;break;
		case '-':res = a-c;break;
		default :res = a*c;
	}
	std::cout<<res;
	return 0;
}