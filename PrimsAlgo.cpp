#include <iostream>
#include <set>
#include <list>
#include <map>
using namespace std;
template<typename T>
class graph
{
	map<T,list<pair<T,int> >  >adjlist;
public:

	void addedge(T u,T v,int dist,bool bidr=true)
	{
		adjlist[u].push_back(make_pair(v,dist));
		if(bidr)
		{
			adjlist[v].push_back(make_pair(u,dist));
		}
	}

	void prims(T src)
	{
		set<pair<int,T> > s;
		map<T,int>distance;

		for(auto k:adjlist)
		{
			distance[k.first]=INT_MAX;
		}

		distance[src]=0;
		s.insert(make_pair(0,src));
		//cout<<src<<" ";
		while(!s.empty())
		{
			auto p=*(s.begin());
			int nodedist=p.first;
			T node=p.second;
			cout<<node<<" -> ";
			s.erase(p);
			for(auto k:adjlist[node])
			{
				if(nodedist+ k.second < distance[k.first])
				{

					auto f=s.find(make_pair(distance[k.first],k.first));
					// if elemt is found delete it  
					if(f!=s.end())
					{
						s.erase(f);
					}
					//then insert it
					// insert it new distance
					distance[k.first]=k.second;
					
					//cout<<k.first<<" ";
					// we insert in s 
					s.insert(make_pair(distance[k.first],k.first));
				}
			}
			//cout<<endl;

		}
	}
};

int main()
{
	graph<string> g;
	g.addedge("A","B",6);
	g.addedge("B","C",4);
	g.addedge("C","D",8);
	g.addedge("D","A",2);
	g.addedge("D","E",3);
	g.addedge("F","E",4);
	g.addedge("E","G",1);
	g.addedge("F","G",2);
	g.prims("E");

	return 0;
}