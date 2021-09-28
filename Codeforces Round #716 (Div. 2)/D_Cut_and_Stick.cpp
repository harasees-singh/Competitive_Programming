#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

// https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/

// Suppose the query-interval has length m. Let's call an element super-frequent if it occurs more than ⌈m2⌉ times in it, 

// with frequency f. If there's no super-frequent element, then we can just put all the elements in 1 subsequence. Otherwise, we need the partitioning. Let's call the rest of the elements (other than the super-frequent one) good elements. 

// One way to partition is to put all the m−f good elements with m−f+1 super-frequent elements; then, put every remaining occurrence of the super-frequent element in a subsequence on its own. The number of subsequences we need here is then 1+f−(m−f+1)=2∗f−m. 

// There's no way to improve this, because: for every subsequence we add, the number of occurrences of the super-frequent element minus the number of good elements is at most 1, so by making it exactly 1 in each subsequence, we get an optimal construction. 

// Now, the problem boils down to calculating f. Note that calculating the most frequent element in general is a well-known slow problem. It's usually solved with MO's algorithm in O(nn−−√log(n)), maybe with a tricky optimization to O(nn−−√). 

// However, notice that we only need the most frequent element if it occurs more than ⌈m2⌉ times. How can we use this fact?

// Randomized solution

// We can pick ~40 random elements from our range to be candidates for the super-frequent element, then count their occurrences and maximize. If there's a super-frequent element, the probability it's not picked is at most 2−40, which is incredibly small.

// To count the number of occurrences of an element in a range, we can carry for each element a vector containing all the positions it occurs in increasing order. Then, upper_bound(r)-lower_bound(l) gives us the number of occurrences in O(log(n)).

// Code link: https://pastebin.com/APHEtfge

int32_t main(){
    FIO


}