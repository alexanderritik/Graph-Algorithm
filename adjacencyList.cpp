#include <iostream>
#include <list>

using namespace std;

class Graph
{

	int V;
	list<int> *l;
public:

	Graph(int v)
	{
		V=v;
		l=new list<int>[v];
	}

	void addEdge(int u,int v,bool bidr=true)
	{
		l[u].push_back(v);
		if(bidr)
			l[v].push_back(u);
	}


	void print()
	{
		for (int i = 0; i < V; ++i)
		{
			cout<<i<<" -> ";
			for(auto k:l[i])
				cout<<k<<" ";
			cout<<endl;
		}
	}
};


int main()
{
	Graph g(5);

	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(1,4);
	g.addEdge(3,4);
	g.addEdge(4,2);
	g.addEdge(1,0);
	g.addEdge(3,0);
	g.addEdge(4,3);
	g.addEdge(0,3);

	g.print();

}
