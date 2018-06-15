#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class QueryTree {

public:
    class Position {
    private:
        int key;
    public:
        Position(int k) : key(k) {}
        friend class QueryTree;
    };


protected:

    vector<T> _array;

public:
    QueryTree()
    : _array(1) {
    }

    int size() const {
        return int(_array.size() - 1);
    }

    QueryTree& operator=(const QueryTree& t) = default;

    QueryTree(const QueryTree& t) = default;

    void print() {
        cout << "size is: " << size() << endl;
        for (int i = 1; i <= size(); i++) {
            cout << _array.at(i) << "\t";
        }
    }
    public:

    void replaceElement(const Position& p, const T& e) {
        _array[p.key] = e;
    }

    Position root() const {
        return Position(_array[1]);
    }

    static bool isRoot(const Position& p) {
        return p.key ==1;
    }

    Position insert(const T& e) {
        _array.push_back(e);
        return (size());
    }
};
