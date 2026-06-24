#pragma once
#include <vector>


struct histo_data {
  int index;
  int number;
  float edge;
};


class histogram {
  public:
    histogram(const int n_points, const int n_bins, const float dist_mean, const float dist_std);

    void make_random_data();

    void bin_hist();

    void plot_hist();

  private:
    int m_n_points;
    int m_n_bins;
    float m_dist_mean;
    float m_dist_std;
    std::vector<float> m_rdm_data;
    std::vector<histo_data> m_bin_edges;

};
    
