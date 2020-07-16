#include <iostream>
#include <list>
#include <map>
#include <stack>

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

	void dfshelper(T node,map<T,bool> &visited, stack<T>&createList)
	{
		visited[node]=true;
		cout<<node<<" -> ";

		for(auto k:adjlist[node])
		{
			if (!visited[k])
			{
				//cout<<k<<endl;
				dfshelper(k,visited,createList);
			}
			
		}

		createList.push(node);
	}

	void dfsTopological()
	{
		//stack works on last in first out
		stack<T>createList;
		map<T,bool>visited;
		
		

		for(auto k:adjlist)
		{
			T node=k.first;
			if(!visited[node])
			{
				dfshelper(node,visited,createList);

				cout<<endl;
			}

		}
		
cout<<endl;

		cout<<"The topological sort is"<<endl;
		while(!createList.empty())
		{
			cout<<createList.top()<<" - > ";
			createList.pop();
		}
	}
};


int main()
{

cout<<endl;
	Graph <string>g1;

	
	
	//g1.addEdge("English","Math",false);
	g1.addEdge("Programming Logic","HTML",false);
	g1.addEdge("Programming Logic","Python",false);
	g1.addEdge("English","Programming Logic",false);
	
	g1.addEdge("Programming Logic","JS",false);
	g1.addEdge("Java","Web development",false);
	g1.addEdge("Python","Web development",false);
	g1.addEdge("HTML","CSS",false);
	g1.addEdge("Math","Programming Logic",false);
	
	g1.addEdge("CSS","JS",false);
	g1.addEdge("JS","Web development",false);
	g1.addEdge("Programming Logic","Java",false);
	//g1.print();
	cout<<"DFS is"<<endl;

	g1.dfsTopological();
	
	cout<<endl;

}
