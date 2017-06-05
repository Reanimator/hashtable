#include "Hastable.h"
#include <iostream>
#include <string>

void main()
{
	Table<int,std::string> t(3);
	t.Add("string1", 15);
	t.Add("string2", 37);
	t.Add("string3", 49);
	t.Add("string4", 41);

	std::cout << t[15] << std::endl;
	std::cout << t[37] << std::endl;
	std::cout << t[49] << std::endl;
	std::cout << t[41] << std::endl<<std::endl;
	int *doubl = t.doublestrickhash();
	for (int i = 0; i < t.getStrike(); i++)
	{
		std::cout << doubl[i] << std::endl;
	}
	t.resize(50);

	std::cin.get();

}