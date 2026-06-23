#include <iostream>
#include <vector>
#include <random>
#include <print>

int main () {


  // Allow user to input N
  int n;
  std::println("Number of samples to produce, N =");
  std::cin >> n;

  if (!std::cin || n < 0) return 1;


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
    data.emplace_back(entry);
    std::println("{}", entry);
  }





}





  
