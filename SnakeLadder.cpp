#include <iostream>
#include <queue>
#include <map>
#include <list>

using namespace std;

template<typename T>
class Graph
{
	map<T, list<T> > adjlist;
public:

	void addEdge(T u,T v,bool bidr=false)
	{
		adjlist[u].push_back(v);
		// if (bidr)
		// {
		//  	adjlist[v].push_back(u);
		// }
	}

	void print()
	{
		for(auto L:adjlist)
		{
			cout<<L.first<<" -> ";
			for (auto K:L.second)
			{
				cout<<K<<" ";
			}
			cout<<endl;
		}
	}

	int shortestPath(T src,T dest)
	{
		queue<T> q;
		map<T,int>dist;
		map<T,T>parent;

		for(auto K:adjlist)
			dist[K.first]=INT_MAX;

		q.push(src);
		dist[src]=0;
		parent[src]=src;
		while(!q.empty())
		{
			T node=q.front();
			cout<<node<<" ";
			q.pop();

			for(auto elem:adjlist[node])
			{
				if(dist[elem]==INT_MAX)
				{
					q.push(elem);
					dist[elem]=dist[node]+1;
					parent[elem]=node;
				}
			}
		}
cout<<endl;
		T temp=dest;
		while(temp!=src)
		{
			cout<<temp<<" -> ";
			temp=parent[temp];
		}
cout<<src<<endl;

		// for(auto k:parent)
		// {
		// 	cout<<k.first<<" "<<k.second<<endl;
		// }

		return dist[dest];

	}
	
};

int main()
{

	Graph<int>g;

	int board[50]={0};
	board[2]=+13;
	board[7]=+20;

	for (int u = 0; u <=36; ++u)
		{
			for (int j = 0; j <=6; j++)
			{
				int v=u	+j+board[u+j];		
			//	cout<<u<<" "<<v<<endl;	
				g.addEdge(u,v);
			}
		}	
//g.print();
	cout<<"The shortest number of chance in which you can reach dest "<<g.shortestPath(1,36)<<endl;

}