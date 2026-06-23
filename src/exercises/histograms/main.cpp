#include <iostream>
#include <vector>
#include <random>
#include <print>

int main () {


  // Allow user to input N
  int n;
  std::cin >> n;

  if (!std::cin || n < 0) return 1;


  // initialise the memory
  std::vector<float> data(n);

  //random number generator
  //add N random numbers to data
  //data~N(0,1)
  
  std::random_device rd;
  std::philox4x64 rne(rd());
  std::normal_distribution norm{0.0, 1.0};

  for (float& e : data) {
    e = norm(rne);
  }

  for (auto& i : data) {
    std::println("{}", i);
  }


}





  
