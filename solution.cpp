#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol568;
using namespace std;

/*takeaways
  - the key idea here is to check whether stay in a city or travel to others
    will benefit you the most by exhausting all the options

  - use a 2-D vector (dp) to record the max vacation days you can take if you
    are currently in city "city" during week "week" after evaluating
    all the options of what do to for the following weeks

  -  example days = [[1,3,1],[6,0,3],[3,3,3]]
     - option 1
       - stay in city 0 for all 3 weeks
       - 1 + 1 + 1 = 3
     - option 2
       - fly to city 1 and stay stay for all
         three weeks
       - 6 + 0 + 3 = 9
     - option 3
       - fly to city 1, stay there for a week;
         then fly to city 0, stay there for a week;
         then fly to city 2, stay there for another week.
       - 6 + 3 + 3 = 12
     - option...

*/

int Solution::maxDays(vector<vector<int>> &flights, vector<vector<int>> &days)
{
  const int n = flights.size();
  const int k = days[0].size();

  /*
    - record the max vacation days you can take
      if you are currently in city "city" during week
      "week" after evaluating all the options what do to
      for the following weeks
  */
  auto dp = vector<vector<int>>(n, vector<int>(k, 0));

  function<int(int, int)> stayOrTravel = [&](int city, int week)
  {
    auto result = 0;
    if (week == k)
      return result;
    /* done evaluating all options */
    if (dp[city][week] > 0)
      return dp[city][week];

    /* two options
      - stay in this city for this week, and check if you
        should continue staying here
      - or fly to other cities and stay there for this week
        and check if you should continue staying there
    */
    for (auto i = 0; i < n; i++)
    {
      if (i == city || flights[city][i])
      {
        /* stay here this week, and check if you should stay here
           for next week as well */
        result = max(result, days[i][week] + stayOrTravel(i, week + 1));
      }
    }
    return dp[city][week] = result;
  };

  return stayOrTravel(0, 0);
}