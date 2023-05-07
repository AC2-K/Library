#include<iostream>
template<typename str>
void putstr(const str&s){
	for(auto c:s)putchar_unlocked(c);

	putchar_unlocked('\n');
}
int main(){
	putstr("COMCOM");
}
