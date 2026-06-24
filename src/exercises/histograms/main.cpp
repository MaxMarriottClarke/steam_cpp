#include "histogram.hpp"

constexpr auto n_bins = 21;
constexpr auto n = 100000;

constexpr auto mean = 0.0f;
constexpr auto deviation = 1.0f;

int main () {

  histogram histo(n, n_bins, mean, deviation);
  histo.make_random_data();

  histo.bin_hist();

  histo.plot_hist();



}





  
