#include <iostream>
#include <map>

using namespace std;


class Graph
{

	int n=5;
	int total_comp=n;
	map<int,int>parent;
public:
	Graph(){

	}

	void addEdge()
	{
		for (int i = 1; i <=n; ++i)
		{
			parent[i]=i;
		}
		
	}



	int superparents(int x)
	{
		if(x==parent[x])
		{
			return x;
		}
		else
		{
			return parent[x]=superparents(parent[x]);
		}
	}

	void mergeit(int x,int y)
	{
		int superparents_x=superparents(x);
		int superparents_y=superparents(y);
		if(superparents_x != superparents_y)
		{
			parent[superparents_x]=superparents_y;
			total_comp--;
		}
cout<<" xis "<<parent[x]<<endl;
		cout<<total_comp<<endl;
	}

};

int main()
{
	Graph g;
	g.addEdge();
	g.mergeit(1,2);
	g.mergeit(3,4);
	g.mergeit(2,3);
	
}