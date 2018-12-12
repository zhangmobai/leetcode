#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval> &intervals) {
	if (intervals.size() == 0) {
		return 0;
	}

	sort(intervals.begin(), intervals.end(), [] (const Interval &l, const Interval &r) { return l.start < r.start; });

	auto comp = [] (const Interval &l, const Interval &r) { return l.end > r.end; };
	priority_queue<Interval, vector<Interval>, decltype(comp)> heap(comp);
	heap.push(intervals[0]);

	for (vector<Interval>::size_type i = 1; i != intervals.size(); ++i) {
		if (intervals[i].start >= heap.top().end) {
			auto in = heap.top();
			heap.pop();
			in.end = intervals[i].end;
			heap.push(in);
		} else {
			heap.push(intervals[i]);
		}
	}

	return heap.size();
}

int main(int argc, char **argv) {
	vector<Interval> v;
	v.push_back(Interval(0,30));
	v.push_back(Interval(15,20));
	v.push_back(Interval(5,10));

	cout << minMeetingRooms(v) << endl;
	
	return 0;
}
