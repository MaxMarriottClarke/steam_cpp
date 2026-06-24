#include <iostream>
#include <vector>
#include <random>
#include <print>
#include "histogram.hpp"


histogram::histogram(const int n_points, const int n_bins,
                     const float dist_mean, const float dist_std)
    : m_n_points(n_points), m_n_bins(n_bins),
      m_dist_mean(dist_mean), m_dist_std(dist_std) {}

void histogram::make_random_data(){

  m_rdm_data.reserve(m_n_points);
  
  std::random_device rd;
  std::philox4x64 rne(rd());
  std::normal_distribution norm{m_dist_mean, m_dist_std};

  
  for (int i = 0; i < m_n_points; i++) {
    auto entry = norm(rne);
    m_rdm_data.push_back(entry);
  }

}

void histogram::bin_hist() {

 const auto max_val = *std::max_element(m_rdm_data.begin(), m_rdm_data.end()); 
 const auto min_val = *std::min_element(m_rdm_data.begin(), m_rdm_data.end()); 

 const auto bin_width = (max_val - min_val) / m_n_bins;

 m_bin_edges.reserve(m_n_bins);


 for (int i = 0; i < m_n_bins; i++) {
   auto b_edge = min_val + i * bin_width;
   histo_data entry = {i, 0, b_edge};
   m_bin_edges.push_back(entry);
 
 }
 
 for (const auto& val : m_rdm_data) {
     const auto bin_idx = std::min(
         static_cast<int>((val - min_val) / bin_width),
         m_n_bins - 1
     );
     m_bin_edges[bin_idx].number++;
 }

}

void histogram::plot_hist() {
  for (const auto& entry: m_bin_edges) {
     std::println("{}", std::string(entry.number, '#'));
  }
}


  

