#include <iostream>
#include <vector>
#include <random>
#include <print>


const int n_bins = 21;
const int n = 1000;

struct histo_data {
  int index;
  int number;
  float edge;
};

void histo(const std::vector<float>& data, const int n_bins) {
  const auto max_val = *max_element(data.begin(), data.end());
  const auto min_val = *min_element(data.begin(), data.end());

  const auto bin_width = (max_val - min_val) / n_bins;
  std::vector<histo_data> bin_edges;
  bin_edges.reserve(n_bins);

  for (int i = 0; i < n_bins; i++) {
    float b_edge = min_val + i * bin_width;
    histo_data entry = {i, 0, b_edge};
    bin_edges.push_back(entry);

  }

  for (const auto& val : data) {
      const int bin_idx = std::min(
          static_cast<int>((val - min_val) / bin_width),
          n_bins - 1
      );
      std::println("{}", bin_idx);
      bin_edges[bin_idx].number++;
  }

  for (const auto& entry : bin_edges) {
      std::println("{}", std::string(entry.number, '#'));
  }


}






int main () {

  // initialise the memory
  std::vector<float> data;
  data.reserve(n);

  //random number generator
  //add N random numbers to data
  //data~N(0,1) 
  std::random_device rd;
  std::philox4x64 rne(rd());
  std::normal_distribution norm{0.0, 1.0};

  for (int i = 0; i < n; i++) {
    auto entry = norm(rne);
    data.push_back(entry);

  }

  histo(data, n_bins);









}





  
