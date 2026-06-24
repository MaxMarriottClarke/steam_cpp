#pragma once
#include <vector>


struct histo_data {
  int index;
  int number;
  float edge;
};


class histogram {
  public:
    histogram(int n_points, int n_bins, float dist_mean, float dist_std);

    void make_random_data();

    void bin_hist();

    void plot_hist();

  private:
    std::vector<float> m_rdm_data;
    std::vector<histo_data> m_bin_edges;
    int m_n_points;
    int m_n_bins;
    float m_dist_mean;
    float m_dist_std;

};
    
