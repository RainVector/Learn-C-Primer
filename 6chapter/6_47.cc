#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using Iter = vector<int>::const_iterator;
void print(Iter first, Iter last)
{
	if(first != last)
	{
		cout<< *first << " ";
		print(++first,last);
	}
}

int main()
{
	
		vector<int> vec{1,2,3,4,5,6};
		print(vec.cbegin(),vec.cend());
		cout<<endl;
		cout<<__FILE__<<" : in function "<<__func__<<" Compiled on"<< __DATE__
			<<" At "<<__TIME__<<endl;

		cout<<endl;
		return 0;
}
