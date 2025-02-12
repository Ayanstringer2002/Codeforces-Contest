
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    int length;
    int id;
};

struct SetComparator {
    bool operator()(const Interval &a, const Interval &b) const {
        return a.start < b.start;
    }
};

struct PriorityQueueComparator {
    bool operator()(const Interval &a, const Interval &b) const {
        return (a.length != b.length) ? (a.length < b.length) : (a.start > b.start);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;
        
        if (size == 1) {
            int temp;
            cin >> temp;
            cout << "YES\n";
            continue;
        }
        
        vector<int> sequence(size + 1);
        for (int i = 1; i <= size; i++) {
            cin >> sequence[i];
        }
        
        vector<int> position(size + 1, 0);
        for (int idx = 1; idx <= size; idx++) {
            position[sequence[idx]] = idx;
        }
        
        bool isValid = true;
        
        if (position[1] != 1 && position[1] != size) {
            cout << "NO\n";
            continue;
        }
        
        if (position[1] == 1 && position[2] != size) {
            cout << "NO\n";
            continue;
        }
        if (position[1] == size && position[2] != 1) {
            cout << "NO\n";
            continue;
        }
        
        int leftBound = min(position[1], position[2]);
        int rightBound = max(position[1], position[2]);
        
        set<Interval, SetComparator> intervalSet;
        priority_queue<Interval, vector<Interval>, PriorityQueueComparator> intervalQueue;
        
        vector<bool> isActive(2 * size, false);
        int intervalID = 0;
        
        auto insertInterval = [&](int left, int right) {
            if (right - left >= 2) {
                Interval newInterval = {left, right, (right - left) / 2, intervalID++};
                intervalSet.insert(newInterval);
                intervalQueue.push(newInterval);
                isActive[newInterval.id] = true;
            }
        };
        
        insertInterval(leftBound, rightBound);
        
        for (int person = 3; person <= size; person++) {
            int assignedSeat = position[person];
            
            while (!intervalQueue.empty() && !isActive[intervalQueue.top().id]) {
                intervalQueue.pop();
            }
            
            int maxGap = intervalQueue.empty() ? -1 : intervalQueue.top().length;
            if (maxGap == -1) {
                isValid = false;
                break;
            }
            
            Interval temp = {assignedSeat, 0, 0, 0};
            auto it = intervalSet.lower_bound(temp);
            if (it == intervalSet.begin()) {
                isValid = false;
                break;
            }
            it--;
            Interval current = *it;
            
            if (!(current.start < assignedSeat && assignedSeat < current.end)) {
                isValid = false;
                break;
            }
            
            if (current.length < maxGap) {
                isValid = false;
                break;
            }
            
            int midPoint = current.start + (current.end - current.start) / 2;
            if ((current.end - current.start) % 2 == 0) {
                if (assignedSeat != midPoint) {
                    isValid = false;
                    break;
                }
            } else {
                if (assignedSeat != midPoint && assignedSeat != midPoint + 1) {
                    isValid = false;
                    break;
                }
            }
            
            isActive[current.id] = false;
            intervalSet.erase(it);
            
            insertInterval(current.start, assignedSeat);
            insertInterval(assignedSeat, current.end);
        }
        
        cout << (isValid ? "YES" : "NO") << "\n";
    }
    return 0;
}
