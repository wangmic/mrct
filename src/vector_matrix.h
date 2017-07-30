#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H
#include "../lib/calculate_hubs.h"
#include <vector>

class vector_matrix final : public i_matrix<double> {
public:
  explicit vector_matrix(const std::vector<std::vector<double>> &data)
      : data_(data) {}

  std::size_t row_size() const override { return data_.size(); }
  std::size_t col_size() const override { return data_[0].size(); }

  const double *operator[](const std::size_t index) const override {
    return &*data_[index].begin();
  }

private:
  const std::vector<std::vector<double>> &data_;
};

std::tuple<std::vector<hub_info>, std::vector<std::size_t>>
calculate_hubs(const std::vector<std::vector<double>> &data,
               const double tn_p = 1, const int k = 500L);
#endif
