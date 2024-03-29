/**
 * @file j608.cpp
 * @author algasami
 * @brief none
 * @date 2023-04-14
 *
 * @copyright Copyright (c) 2023
 *
 * This is a variant of the time scheduling problem. We can solve it with
 * dynamic programming and greedy:
 * Given n intervals and k machines, find the highest number of intervals
 * occupied by concurrent machines.
 * This question involves the following hypothesis (or conjecture since I don't
 * know how to prove it):
 * 1. For k=1, selecting the interval that ends the earliest leaves the maximum
 * number of possible intervals in the future (we are always propagating
 * forward).
 * 2. For k>1, combined with the first statement, which is true also in this
 * circumstance, using the machine that ends the latest can help us with finding
 * the answer to the global maxima, and unused machines should always be
 * reserved **unless none could be chosen**.
 *
 * The reason for prioritizing machines which ends the latest is that as we move
 * to the future, the possibility of machines working relatively **early** being
 * able to be assigned to the intervals increases, so we reserve those with
 * early tasks by using machines with latest tasks.
 * That for unused machines is also quite similar to the above. Since unused
 * machines are guaranteed to work given any intervals, they are the last cards
 * we want to play.
 */

#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> intervals[100007], occupied[107];
inline void dbg_int()
{
    for (int i = 0; i < n; i++)
        printf("%d %d\n", intervals[i].first, intervals[i].second);
}
inline void reset_occupied(int index)
{
    occupied[index] = make_pair(-1, -1);
}
inline bool overlapping(int interval_index, int machine_index)
{
    const pair<int, int> &a = intervals[interval_index];
    const pair<int, int> &b = occupied[machine_index];
    return (a.first <= b.second && b.first <= a.second);
}
inline bool is_occupied(int index)
{
    return occupied[index].first >= 0 && occupied[index].second >= 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
        reset_occupied(i);
    for (int i = 0; i < n; i++)
        scanf("%d", &intervals[i].first);
    for (int i = 0; i < n; i++)
        scanf("%d", &intervals[i].second);

    sort(intervals, intervals + n,
         [](const auto &pa, const auto &pb) { return pa.second < pb.second; });
    int festival_count = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false; // for old ints
        int furthest_machine_pos = -1;
        int min_machine_index = 0;
        for (int j = 0; j < k; j++)
        {
            if (is_occupied(j))
            {
                if (!overlapping(i, j))
                {
                    int pos = occupied[j].second;
                    if (pos > furthest_machine_pos)
                    {
                        furthest_machine_pos = pos;
                        min_machine_index = j;
                        found = true;
                    }
                }
            }
            else
            {
                found = true;
                min_machine_index = j;
            }
        }
        if (found)
        {
            festival_count++;
            occupied[min_machine_index] = intervals[i];
        }
    }
    printf("%d", festival_count);
    return 0;
}