#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Pair {
    int index;
    int value;
    Pair() {};
    Pair(int i, int v) : index(i), value(v) {};
};

class IntensitySegments {
  private:
    list<Pair> intervals;

  public:
    void add(int from, int to, int amount) {
        do_operator(from, to, amount, false);
    }

    void set(int from, int to, int amount) {
        do_operator(from, to, amount, true);
    }

    void do_operator(int from, int to, int amount, bool for_add) {
        if (intervals.size() == 0) {
            intervals.push_back(Pair(from, amount));
            intervals.push_back(Pair(to, 0));
            return;
        }

        // handle "from"
        list<Pair>::iterator iter = intervals.begin();
        int cur_value = 0;
        while (iter != intervals.end()) {
            if (iter->index == from) {
                if (for_add) {
                    iter->value += amount;
                } else {
                    iter->value = amount;
                }
                iter++;
                break;
            } else if (iter->index > from) {
                intervals.insert(iter, Pair(from, cur_value + amount));
                break;
            }
            cur_value = iter->value;
            iter++;
        }

        // handle "to"
        while (iter != intervals.end()) {
            if (iter->index == to) {
                break;
            } else if (iter->index < to) {
                if (for_add) {
                    iter->value += amount;
                } else {
                    iter->value = amount;
                }
                iter++;
            } else if (iter->index > to) {
                break;
            }
        }
        if (iter == intervals.end()) {
            intervals.push_back(Pair(to, 0));
        }

        // delete redundant begin
        iter = intervals.begin();
        while (iter != intervals.end()) {
            if (iter->value != 0) {
                break;
            }
            intervals.erase(iter);
            iter = intervals.begin();
        }

        // delete redundent end
        list<Pair>::reverse_iterator r_iter = intervals.rbegin();
        while (r_iter != intervals.rend() && r_iter->value == 0) {
            r_iter++;
            if (r_iter == intervals.rend()) {
                break;
            }
            if (r_iter->value == 0) {
                intervals.erase(r_iter.base());
            } else {
                break;
            }
            r_iter = intervals.rbegin();
        }
    }

    string to_string() {
        stringstream s;
        s << "[";
        for (list<Pair>::iterator iter = intervals.begin();
             iter != intervals.end();) {
            s << "[" << iter->index << ", " << iter->value << "]";
            iter++;
            if (iter != intervals.end()) {
                s << ", ";
            }
        }
        s << "]";
        return s.str();
    }
};

void test_intensity_segments() {
    cout << "test 1" << endl;
    IntensitySegments *segments = new IntensitySegments();
    cout << segments->to_string() << endl; // Should be "[]"

    segments->add(10, 30, 1);
    cout << segments->to_string() << endl; // [[10, 1], [30, 0]]

    segments->add(20, 40, 1);
    cout << segments->to_string()
         << endl; // [[10, 1], [20, 2], [30, 1], [40, 0]]

    segments->add(10, 40, -2);
    cout << segments->to_string()
         << endl; // [[10, -1], [20, 0], [30, -1], [40, 0]]
}

void test_intensity_segments_2() {
    cout << "test 2" << endl;
    IntensitySegments *segments = new IntensitySegments();
    cout << segments->to_string() << endl; // Should be "[]"

    segments->add(10, 30, 1);
    cout << segments->to_string() << endl; // Should be "[[10,1],[30,0]]"

    segments->add(20, 40, 1);
    cout << segments->to_string()
         << endl; // Should be "[[10,1],[20,2],[30,1],[40,0]]"

    segments->add(10, 40, -1);
    cout << segments->to_string() << endl; // Should be "[[20,1],[30,0]]"

    segments->add(10, 40, -1);
    cout << segments->to_string()
         << endl; // Should be "[[10,-1],[20,0],[30,-1],[40,0]]"
}

int main() {
    test_intensity_segments();
    test_intensity_segments_2();
    return 0;
}