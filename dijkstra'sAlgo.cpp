#include <iostream>
using namespace std;

template<typename T>
class graph
{
	map<T, list< pair<T,int> > > adjlist;
public:
	void addedge(T u,T v,int dist,bool bidr=true)
	{
		adjlist[u].push_back(make_pair(v,dist));
		if(bidr)
			adjlist[v].push_back(make_pair(u,dist));
	}

	void print()
	{
		for(auto k:adjlist)
		{
			cout<<k.first<<" -> ";
			for(auto l:k.second)
				cout<<l.first<<" "<<l.second<<" - >";
			cout<<endl;
		}

	}

	// void dijkstra(T src)
	// {
	// 	set< pair<int,T> > minidist;
	// 	map<T,bool>visited;
	// 	//map<T,T>parent

	// 	visited[src]=true;
	// 	minidist.insert(make_pair(0,src));

	// 	while(!minidist.empty())
	// 	{
	// 		node=minidist[0].second;

	// 		for(auto k:adjlist[node])
	// 		{
	// 			minidist.insert(make_pair(k.second,k.first));

	// 		}

	// 	}


	// 	minidist.insert()
	// }
};


int main()
{
	graph<int> g;
	g.addedge(1,2,1);
	g.addedge(1,3,4);
	g.addedge(2,3,1);
	g.addedge(3,4,2);
	g.addedge(1,4,7);
	g.print();

}