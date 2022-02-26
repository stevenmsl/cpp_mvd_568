#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol568;

/*
Example 1:
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
Output: 12
Explanation:
Ans = 6 + 3 + 3 = 12.
*/
tuple<vector<vector<int>>, vector<vector<int>>, int>
testFixture1()
{
  auto flights = vector<vector<int>>{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  auto days = vector<vector<int>>{{1, 3, 1}, {6, 0, 3}, {3, 3, 3}};
  return make_tuple(flights, days, 12);
}

/*
Input: flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
Output: 3
Explanation:
Ans = 1 + 1 + 1 = 3.
*/

tuple<vector<vector<int>>, vector<vector<int>>, int>
testFixture2()
{
  auto flights = vector<vector<int>>{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  auto days = vector<vector<int>>{{1, 1, 1}, {7, 7, 7}, {7, 7, 7}};
  return make_tuple(flights, days, 3);
}

/*
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
Output: 21
Explanation:
Ans = 7 + 7 + 7 = 21
*/
tuple<vector<vector<int>>, vector<vector<int>>, int>
testFixture3()
{
  auto flights = vector<vector<int>>{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  auto days = vector<vector<int>>{{7, 0, 0}, {0, 7, 0}, {0, 0, 7}};
  return make_tuple(flights, days, 21);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::maxDays(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::maxDays(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::maxDays(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}