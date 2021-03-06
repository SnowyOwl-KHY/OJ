#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> arrange;
        vector< vector<int> > courseGraph(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
        	int course = prerequisites[i].first;
        	int requiredCourse = prerequisites[i].second;
        	courseGraph[requiredCourse].push_back(course);
        	indegrees[course]++;
        }
        queue<int> q;
        int i;
        for (i = 0; i < indegrees.size(); i++) {
        	if (indegrees[i] == 0) {
        		q.push(i);
        	}
        }
		while (!q.empty()) {
			int course = q.front();
			q.pop();
			arrange.push_back(course);
			for (int i = 0; i < courseGraph[course].size(); i++) {
				int & adjCourse = courseGraph[course][i];
				indegrees[adjCourse]--;
				if (indegrees[adjCourse] == 0) {
					q.push(adjCourse);
				}
			}
		}
        if (arrange.size() < numCourses) {
            return vector<int>();
        } else {
		  return arrange;
        }
    }
};

int main() {
    return 0;
}