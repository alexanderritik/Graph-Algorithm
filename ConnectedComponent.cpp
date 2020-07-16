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

		cout<<endl;

		for(auto k:adjlist)
		{
			//cout<<k.first<<" "<<k.second<<endl;
			if(visited[k.first]!=true){
				dfshelper(k.first,visited);
				cout<<endl;
			}

		}
		
	}
};


int main()
{

cout<<endl;
	Graph <string>g1;

	g1.addEdge("Amritsar","Jaipur");
	g1.addEdge("Amritsar","Delhi");
	g1.addEdge("Delhi","Jaipur");
	g1.addEdge("Mumbai","Jaipur");
	g1.addEdge("Mumbai","Bhopal");
	g1.addEdge("Mumbai","Banglore");
	g1.addEdge("Delhi","Bhopal");
	g1.addEdge("Agra","Delhi");
	g1.addEdge("Andaman","Nicobar");
	g1.addEdge("Phillipines","Vietnam");
	//g1.print();
	cout<<"DFS is"<<endl;

	g1.dfs("Amritsar");

}
