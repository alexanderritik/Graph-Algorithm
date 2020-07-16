#include <iostream>
#include <set>
#include <map>
#include <list>
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

	void dijkstra(T src)
	{
		set< pair<int,T> > minidist;
		map<T,int>distance;
		//pair<int ,T> *node;
		//map<T,T>parent

		for(auto k:adjlist)
		{
			distance[k.first]=INT_MAX;
		}

		distance[src]=0;
		minidist.insert(make_pair(0,src));

		while(!minidist.empty())
		{
			auto p= *(minidist.begin());
			T node= p.second;
			int nodedist=p.first;

			minidist.erase(minidist.begin()); 

			for(auto child_pair:adjlist[node])
			{
				if(nodedist+child_pair.second < distance[child_pair.first]){ 

					//in set updation of a particular. node is not possible so
					//first we remove it then again insert it 
					//since set insert element ain arrnged way 
					T dest=child_pair.first;

					auto f=minidist.find(make_pair(distance[dest],dest));
					// if elemt is found delete it  
					if(f!=minidist.end())
					{
						minidist.erase(f);
					}
					//then insert it

					// insert it new distance
					distance[dest]=nodedist+child_pair.second;

					// we insert in set 
					minidist.insert(make_pair(distance[dest],dest));
				}
			}

		}


		for(auto l:distance)
		{
			cout<<l.first<<" distance from source is "<<l.second<<endl;
		}
	}
};


int main()
{
	// graph<int> g;
	// g.addedge(1,2,1);
	// g.addedge(1,3,4);
	// g.addedge(2,3,1);
	// g.addedge(3,4,2);
	// g.addedge(1,4,7);
	// g.print();
	// cout<<endl;

	// g.dijkstra(1);

	graph<string>g1;
	g1.addedge("Amritsar","Delhi",1);
	g1.addedge("Amritsar","Jaipur",4);
	g1.addedge("Jaipur","Delhi",2);
	g1.addedge("Jaipur","Mumbai",8);
	g1.addedge("Bhopal","Agra",2);
	g1.addedge("Mumbai","Bhopal",3);
	g1.addedge("Agra","Delhi",1);

	g1.print();
	cout<<endl;
	cout<<"Now dijkstra algo "<<endl;
	g1.dijkstra("Amritsar");


}