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

	void dfshelper(T node,map<T,bool> &visited)
	{
		visited[node]=true;
		cout<<node<<" -> ";

		for(auto k:adjlist[node])
		{

			if (!visited[k])
			{
				//cout<<k<<endl;
				dfshelper(k,visited);
			}
			
		}
	}

	void dfs(T src)
	{
		map<T,bool>visited;
		dfshelper(src,visited);
	}
};


int main()
{

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
	cout<<"DFS is"<<endl;

	g1.dfs(0);

}
