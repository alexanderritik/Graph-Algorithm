#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;

template<typename T>
class Graph
{

	map<T,list<T>> adjlist;
public:
	Graph(){

	}

	void addEdge(T u,T v,bool bidr=true)
	{
		adjlist[u].push_back(v);
		if(bidr)
			adjlist[v].push_back(u);
	}


	void print()
	{
			
			for(auto object:adjlist)
			{
				cout<<object.first<<"-> ";
				for(auto elem:object.second)
					cout<<elem<<" ";
				cout<<endl;
			}
	}

};


int main()
{
	Graph <string>g;

	g.addEdge("Putin","Trump",true);
	g.addEdge("Modi","Trump",true);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Putin","Pope",false);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Yogi","Prabhu",false);

	g.print();
cout<<endl;
	Graph <int>g1;

	g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(0,4);
	g1.addEdge(2,4);
	g1.addEdge(2,3);
	g1.addEdge(3,5);
	g1.addEdge(3,4);

	g1.print();


}
