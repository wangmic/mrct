#include "../lib/calculate_hubs.h"
#include "fopen_matrix.h"
#include "vector_matrix.h"
#include <fstream>
#include <iostream>

void show_usage(char *exe_name, const char *text) {
  std::cerr << text << std::endl;
  std::cerr << "\tUsage: " << exe_name << " "
            << "<input file name> <output file name> [TN_p]" << std::endl;
  std::cerr << "\tExample: " << exe_name << " "
            << "testdata/E_coli_anaerobic.txt E_coli_anaerobic.out 0.0025"
            << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    show_usage(argv[0], "File name should not be omitted.");
    return -1;
  }
  double tn_p = 1;
  if (argc > 3) {
    char *e;
    errno = 0;
    tn_p = std::strtod(argv[3], &e);

    if (*e != '\0' || errno != 0) {
      show_usage(argv[0], "TN_p should be double.");
      return -2;
    }
  }

  const auto input_file_name = argv[1];
  const auto output_file_name = argv[2];
  const auto matrix = FopenMatrix::load_matrix<double>(input_file_name, false);

  std::vector<hub_info> hub_info_all;
  std::vector<std::size_t> mr_id;
  std::tie(hub_info_all, mr_id) = calculate_hubs(matrix.get_data(), tn_p);

  std::fstream fs;
  fs.open(output_file_name, std::fstream::out | std::fstream::trunc);
  for (auto &hub_info : hub_info_all)
    if (hub_info.if_hub > 0)
      fs << hub_info.if_hub << "\t" << hub_info.cluster_bound << "\t"
         << hub_info.index << std::endl;
  return 0;
}
