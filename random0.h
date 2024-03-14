//QT版不重复随机数生成
#ifndef RANDOM0_H
#define RANDOM0_H

#include <QSet>
#include <QRandomGenerator>

template <typename IntType = int>
class DistinctUniformIntDistribution {
public:
    using result_type = IntType;

private:
    using set_type = QSet<result_type>;

public:
    DistinctUniformIntDistribution(result_type inf, result_type sup) :
        inf_(inf),
        sup_(sup),
        range_(sup_ - inf_ + 1)
    {}

    void reset() {
        uset_.clear();
    }

    template <typename Generator>
    result_type operator()(Generator& engine) {
        if (!(uset_.size() < range_)) {
            qFatal("Range exhausted");
        }

        result_type res;
        do {
            res = QRandomGenerator::global()->bounded(inf_, sup_ + 1);
        } while (uset_.contains(res));

        uset_.insert(res);
        return res;
    }

    result_type min() const {
        return inf_;
    }

    result_type max() const {
        return sup_;
    }

private:
    const result_type inf_;
    const result_type sup_;
    const size_t range_;
    set_type uset_;
};


#endif // RANDOM0_H
