#include "vector_matrix.h"
#include "../lib/calculate_hubs.h"
#include <memory>

std::tuple<std::vector<hub_info>, std::vector<std::size_t>>
calculate_hubs(const std::vector<std::vector<double>> &data,
               const double tn_p /*= 0.0025*/, const int k /*= 1000L*/) {
  return calculate_hubs(*std::make_unique<vector_matrix>(data), tn_p, k);
}
