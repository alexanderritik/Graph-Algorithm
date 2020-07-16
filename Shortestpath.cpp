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

	void shortespath(T src)
	{
		queue<T> q;
		map<T,int>dist;
		q.push(src);
		map<T,T>parent;
		//fill all the dist of elment to INT_MAX means infinity 
		for(auto k:adjlist)
			dist[k.first]=INT_MAX;


		dist[src]=0;
		parent[src]=src;
		//if queue bcome empty then it returns true which is false

		while(!q.empty())
		{
			//it is use to select the first elemnt from the queue 
			T node=q.front();
			//cout<<node<<" - > ";
			// it will removes the first element from the queue 
			q.pop();

				for(auto elem:adjlist[node])
				{
					//cout<<elem<<endl;
					if(dist[elem]==INT_MAX)
					{
					q.push(elem);
					dist[elem]=dist[node] + 1;
					parent[elem]=node;
				    }
				}

		}
cout<<"This is showing the distance of node from source node given"<<endl;
	for (auto k :dist)
	{
		//T node=k.first;
		cout<<k.first<<" Distance from "<<src<<" is "<<k.second<<endl;
	}

cout<<"this is Maintaing the source and child"<<endl;
	for(auto k:parent)
	{
		cout<<k.first<<" "<<parent[k.first]<<endl;
	}

	}
};


int main()
{

	Graph <int>g1;

	g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(0,4);
	g1.addEdge(2,4);
	g1.addEdge(2,3);
	g1.addEdge(3,5);
	g1.addEdge(3,4);

	g1.print();


	g1.shortespath(0);

}
