#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool compare(Interval a, Interval b) {
	return (a.start==b.start)?a.end<b.end:a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> result;
        if(n<=0) return result;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i=0; i<n; i++) {
        	int size = result.size();
        	if(size>0 && result[size-1].end>=intervals[i].start) {
        		if(result[size-1].end<intervals[i].end) {
        			result[size-1].end = intervals[i].end;
        		}
        	}else {
        		result.push_back(intervals[i]);
        	}
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    Solution s;    
	vector<Interval> r = s.merge(intervals);
	for(int i=0; i<r.size(); i++)
		cout << r[i].start << " " << r[i].end << endl;	
	return 0;
}
