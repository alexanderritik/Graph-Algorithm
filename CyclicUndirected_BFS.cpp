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

	void checkCyclic(T src)
	{
		queue<T> q;
		map<T,bool>visited;
		int flag=0;
		q.push(src);

		map<T,T>parent;

		visited[src]=true;
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
					if(!visited[elem])
					{
					q.push(elem);
					visited[elem]=true;
					parent[elem]=node;
					//cout<<elem<<" "<<node<<endl;
				    }
				    else{
				 		//this condition come when node is alredy visted 
				 		//and the parent of that elemt is not node
				 	//	cout<<elem<<" "<<parent[elem]<<" "<<node<<endl;

				    	//u can also use this condition in upper if condition with && operation
				    	if(parent[node]!=elem)
				    	{
				    		flag=1;
				    		break;
				    	}
				    }
				}
				if(flag==1){
					cout<<"Cycle is formed"<<endl;
					break;
				}

		}
}

// cout<<"this is Maintaing the source and child"<<endl;
// 	for(auto k:parent)
// 	{
// 		cout<<k.first<<" "<<parent[k.first]<<endl;
// 	}

// 	}
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


	g1.checkCyclic(0);

}
