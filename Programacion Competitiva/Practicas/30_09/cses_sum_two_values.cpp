#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>

using ll = long long;

using vi = std::vector<int>; // vector of ints
#define pb push_back // easier to add elements to a vector
#define all(x) begin(x), end(x) // for iterating a container
#define sz(x) (int) (x).size() // size of a container

using pi = std::pair<int,int>; // pair of ints
#define f first // easier to access members of a pair (first)
#define s second // easier to access members of a pair (second)
#define mp make_pair // to create a pair (just like std::make_pair)

int main() {
	ll N, X;
	std::cin >> N >> X;
	std::vector<std::pair<int,int>> vector_pair; // vector of pairs
	
	// append the element and its index
	for (int i = 0; i < N; i++) {
		ll x;
		std::cin >> x; // read the element
		vector_pair.pb({x, i + 1}); // append the element and its index
	}
	
	sort(vector_pair.begin(), vector_pair.end()); // sort the vector of pairs
	int i = 0, j = N - 1; // start and end indices
	
	while (i < j) { // while there are elements to sum
		// adjust left and right pointers.
		if(vector_pair[i].f + vector_pair[j].f > X)
			j--;
		else if (vector_pair[i].f + vector_pair[j].f < X)
			i++;
		else if (vector_pair[i].f + vector_pair[j].f == X) { 
			std::cout << vector_pair[i].s << " " << vector_pair[j].s; // print the indices
            return 0; // exit
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
