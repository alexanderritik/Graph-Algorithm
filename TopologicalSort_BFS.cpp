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

	void bfsTopological()
	{
		queue<T> q;
		map<T,bool>visted;
		map<T,int>indegree;

		//this is use to amke intial all vertex are unvisted and indegree  is 2
		for(auto k:adjlist)
		{
			T node=k.first;
			visted[node]=false;
			indegree[node]=0;
		}
		
		//now we use to make the indegree of all vertex as given
		for (auto k:adjlist)
		{
			T node=k.first;
			for(auto l:k.second)
			{
				indegree[l] +=1;
			}
		}

		//lets view the indegree
		for (auto k:indegree)
		{
			T node=k.first;
			cout<<k.first<<" "<<k.second<<endl;
			if(k.second==0)
			{
				q.push(node);
			}
		}

		while(!q.empty())
		{
			T node=q.front();
			q.pop();
			cout<<node<<" -> ";
			for(auto k:adjlist[node])
			{

				indegree[k]--;
				if(indegree[k]==0)
				{
					q.push(k);
				}

			}
		}



	}
};


int main()
{

	Graph <string>g1;

	g1.addEdge("English","Programming Logic",false);
	g1.addEdge("Math","Programming Logic",false);
	//g1.addEdge("English","Math",false);
	g1.addEdge("Programming Logic","HTML",false);
	g1.addEdge("Programming Logic","Python",false);
	g1.addEdge("Programming Logic","Java",false);
	g1.addEdge("Programming Logic","JS",false);
	g1.addEdge("Java","Web development",false);
	g1.addEdge("Python","Web development",false);
	g1.addEdge("HTML","CSS",false);
	g1.addEdge("CSS","JS",false);
	g1.addEdge("JS","Web development",false);

	//g1.print();
	cout<<"BFS Topological sort is"<<endl;

	g1.bfsTopological();
	
	cout<<endl;

}
