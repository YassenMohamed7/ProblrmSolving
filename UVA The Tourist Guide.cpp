#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define int long long

const int N = 1e5+5;
struct DSU
{
	int parent[N];
	int setSize[N];
	DSU()
	{
		for (int i = 0; i < N; ++i)
		{
			parent[i] = i;
			setSize[i] = 1;
		}
	}
	int find(int u)
	{
		if(parent[u] == u)
		return u;
		return parent[u] = find(parent[u]);  // pass compression
	}

	bool inSameSet(int a, int b)
	{
		return find(a) == find(b);
	}


	void merge(int a, int b)
	{
		int root1 = find(a);
		int root2 = find(b);
		if(root1 == root2)
			return;

		if(setSize[root1] > setSize[root2])
			swap(root1, root2);
		parent[root2] = root1;      
		setSize[root1]+= setSize[root2];
	}

	int count(int n)
	{
		return setSize[find(n)];
	}

};


int32_t main()
{

	int n, m;
	int tc = 1;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;

		DSU dsu;
		vector<pair<int, pair<int, int>>> v;   // weight, from, to 
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			--c;                // he need a seat for himself in each trip.
			v.push_back({c, {a, b}});
		}
		sort(v.rbegin(), v.rend());   // sort the edges in descending way according to the weight.

		int from, to, need;
		cin >> from >> to >> need;   // get the source which the tourists are and the destination where they want to go.
		for (int i = 0; i < m; ++i)  // loop for the roads after ordering them form high to low capacity. 
		{
			int w = v[i].F;
			int a = v[i].S.F;
			int b = v[i].S.S;
			if(!dsu.inSameSet(a, b)) // if there is no road form a to b
      {                         // connect a and b.
				dsu.merge(a, b);
				if(dsu.inSameSet(from, to))       // if we found a road form source to destination
				{                                 // so we have a road between  source and destination with maximum capacity.
                                          // and the current road is the lowest capacity one on the way form source to destination.
					cout << "Scenario #" << tc++ << endl       
                         << "Minimum Number of Trips = "
                         << (need + w-1) / w
                         << endl << endl;
                    break;
				}
			}
		}

	}
	

	return 0;
}
