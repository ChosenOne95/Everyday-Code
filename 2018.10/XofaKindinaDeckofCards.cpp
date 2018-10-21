/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000

*/
//c++ 写法
bool hasGroupsSizeX(vector<int>& deck) {
	unordered_map<int, int> count;
	int res = 0;
	for (int i : deck) count[i]++;//计数，哈希思想？散列是啥来着。
	for (auto i : count) res = __gcd(i.second, res);
	return res > 1;
}


//c写法
bool hasGroupsSizeX(int* deck, int deckSize) {
	if (deckSize == 1)
		return false;
	int group[deckSize];
	memset(group, 0, sizeof(group));//初始化数组
	int min = 2;
	int i;
	for (i = 0; i < deckSize; i++) {
		group[deck[i]] += 1;//计数，哈希思想？
	}

	i = 0;
	while (i < deckSize) {
		if (group[i] % min) {
			min++;
			i = 0;
		}
		i++;
		if (min > deckSize)
			break;
	}
	return i == deckSize;
}
