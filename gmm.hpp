//
// Created by mattk on 2020-04-29.
//

#ifndef GMM_GMM_HPP
#define GMM_GMM_HPP

#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>

template<typename ValueT> //, typename ArrayT = std::vector<std::vector<ValueT>>>
class Gmm {
public:
    using Array2dT = std::vector<std::vector<ValueT>>;

    Gmm(const Array2dT &data, size_t clusters, const Array2dT& initialCenters)
            : data_(data), dimension_(data[0].size()), clusters_(clusters)
    {
        assert(means_.size() == clusters);
        assert(means_.front().size() == dimension_);

        // Copy initialCenters
        means_.reserve(clusters_);
        for (size_t c = 0; c < clusters_; ++c)
        {
            std::vector<ValueT> clusterCenter;
            clusterCenter.reserve(dimension_);
            for (size_t d = 0; d < dimension_; ++d)
            {
                clusterCenter.push_back(initialCenters[c][d]);
            }
            means_.push_back(std::move(clusterCenter));
        }
    }

    void train()
    {
        
    }

    std::vector<ValueT> predict(const Array2dT &data, bool isRowMajor = true) const
    {
//        for (size_t i = 0; i < )
    }

private:
    static double gaussian(double x, double mu, double sigma)
    {
        return 1 / (sigma * std::sqrt(2 * M_PI)) * std::exp(-std::pow(x - mu, 2) / (2 * sigma * sigma));
    }

    std::vector<std::vector<ValueT>> means_;
    std::vector<std::vector<ValueT>> stdDevs_;
    const Array2dT &data_;
    const size_t dimension_ = 0;
    const size_t clusters_ = 0;
};

#endif //GMM_GMM_HPP
