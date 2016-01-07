#include <iostream>
#include <map>
#include <vector>
#include <string>

const char *name[] = {
	"astring", 
	"bstring", 
	"cstring", 
	"dstring", 
};
/*
 *const char *bname[] = {
 *        "aastring", 
 *        "bbstring", 
 *        "ccstring", 
 *        "ddstring", 
 *};
 */

int main(void)
{
	std::map<int,std::vector<std::string*> > m_list;

	std::vector<std::string*>*	sName;
	std::string	*s;
	for (int j = 0; j < 2; j++)
	{
		sName = new std::vector<std::string*>;
		for (int i = 0; i < 4; i++)
		{
			//push the string pointer so needn`t free
			s = new std::string(name[i]);
			(*sName).push_back(s);
		}
		m_list[j] = *sName;
		delete	sName;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < m_list[i].size(); j++)
		{
			std::cout<<*(m_list[i][j])<<std::endl;
		}
	}
	return 0;
}
