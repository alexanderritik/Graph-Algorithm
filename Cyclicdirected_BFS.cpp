#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;

template<typename T>
class Graph
{
	//
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

	bool dfshelper(T node,map<T,bool> &visited,map<T,bool>  &instack)
	{
		
		instack[node]=true;
		visited[node]=true;
		//cout<<node<<" -> ";

		for(auto k:adjlist[node])
		{
//here we check if it is not visited and call one again itself
  // but instack node is true means it is already in the chain  
			if ((!visited[k] && dfshelper(k,visited,instack)) || instack[k]==true)
			{
				    return true;
			}	
		}
		//this is use to remove from the stack
		instack[node]=false;
return false;
		
	}

	void Checkcyclic()
	{
		map<T,bool>instack;
		map<T,bool>visited;

		for(auto k:adjlist)
		{
			T node=k.first;
			if(!visited[node])
			{
				bool cyclepresent=dfshelper(node,visited,instack);
				if(cyclepresent)
					cout<<"The cycle is present"<<endl;
				else
					cout<<"cycle is not present"<<endl;
			}
		}
  
        
		 
	}
};


int main()
{

cout<<endl;
	Graph <int>g1;

	g1.addEdge(0,1,false);
	g1.addEdge(0,2,false);
	g1.addEdge(2,3,false);
	g1.addEdge(2,4,false);
	g1.addEdge(1,5,false);
	g1.addEdge(3,0,false);


	g1.print();
	cout<<"DFS is"<<endl;

	g1.Checkcyclic();

}
