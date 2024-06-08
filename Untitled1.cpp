#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class abc
{
	vector<int> v;
	public:
		abc()
		{
			
		}
		
		void push(int data)
		{
			v.push_back(data);
		}
		
		void print()
		{
			for(auto i:v)
			{
				cout<<i<<" ";
			}
		}
};

int main()
{
	abc a, temp;
	a.push(6);
	a.push(7);
	a.push(5);
	a.push(3);
	a.push(1);
	a.print();
	
	ofstream os("text.dat", ios::out | ios::binary);
	os.write((char*)&a, sizeof(abc));
	os.close();
	
	ifstream on("text.dat", ios::in | ios::binary);
	on.read((char*)&temp, sizeof(abc));
	temp.print();
	on.close();
}