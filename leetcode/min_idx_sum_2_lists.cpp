// b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*

599. Minimum Index Sum of Two Lists My SubmissionsBack To Contest

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

https://leetcode.com/contest/leetcode-weekly-contest-34/problems/minimum-index-sum-of-two-lists/
*/

#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> st;
		multimap<int, string> res_map;
		vector<string> res;

		for (int x = 0; x < list1.size(); ++x) {
			st.insert(std::pair<string, int>(list1[x],x));
		}

		for (int y = 0; y < list2.size(); ++y) {
			auto it = st.find(list2[y]);
			if (it != st.end()) {
				res_map.insert(std::pair<int, string>(it->second + y, list2[y]));
			}
		}
		if (res_map.size() == 1) {
			res.push_back(res_map.begin()->second);
			return res;
		}

		else if (res_map.size() > 1) {

			int idx = res_map.begin()->first;
			auto it = res_map.begin();
			for (; it != res_map.end(); ++it) {
				if (it->first != idx) break;
				res.push_back(it->second);
			}
		}
		return res;
	}
};


int main()
{
	// test case 1
	vector<string> v1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> v2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };

	Solution s;
	vector<string> res = s.findRestaurant(v1, v2);

	// test case 2
	vector<string> v3 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> v4 = { "KFC", "Shogun", "Burger King" };

	Solution s2;
	vector<string> res2 = s2.findRestaurant(v3, v4);

	// test case 3
	vector<string> v5 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> v6 = { "KFC", "Burger King", "Tapioca Express", "Shogun" };

	Solution s3;
	vector<string> res3 = s3.findRestaurant(v5, v6);
    return 0;
}

