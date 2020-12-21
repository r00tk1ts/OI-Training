#include <vector>
#include <numeric>

template<typename T = long long>
class UnionFindSet {
public:
    UnionFindSet(T n) : m_leader(n) { iota(m_leader.begin(), m_leader.end(), 0); }
    T findRoot(T x) { return m_leader[x] == x ? x : (m_leader[x] = findRoot(m_leader[x]));}
    virtual void unionSets(T x, T y) {
        m_leader[findRoot(x)] = findRoot(y);
    }
protected:   
    std::vector<T> m_leader;
};

template<typename T = long long>
class HeuristicUnionFindSet : public UnionFindSet<T> {
public:
    HeuristicUnionFindSet(T n) : UnionFindSet<T>(n), m_rank(n) {}
    virtual void unionSets(T x, T y) override {
        T fx = UnionFindSet<T>::findRoot(x), fy = UnionFindSet<T>::findRoot(y);
        if(m_rank[fx] <= m_rank[fy]) {
            UnionFindSet<T>::m_leader[fx] = UnionFindSet<T>::m_leader[fy];
        } else {
            UnionFindSet<T>::m_leader[fy] = UnionFindSet<T>::m_leader[fx];
        }

        if(m_rank[fx] == m_rank[fy] && fx != fy) {
            m_rank[fy]++;
        }
    }
private:
    std::vector<T> m_rank;
};