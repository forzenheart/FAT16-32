#include <string>
#include <iostream>

using namespace std;

int
main(void)
{
	std::string	s = "string";
	cout<<(s + char(1 + 'a')).c_str()<<endl;
	return 0;
}
