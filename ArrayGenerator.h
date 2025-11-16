#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H
#include <random>
#include <vector>
class ArrayGenerator {
  std::vector<int> arr = std::vector<int>(100000);
  std::random_device rd{};
  unsigned int seed{};
  std::mt19937 generator;
  std::uniform_int_distribution<int> distribution = std::uniform_int_distribution<int>(0, 6000);

  std::vector<int> RandomArray(int length);
  static std::vector<int> ReversedArray(int length);
  std::vector<int> AlmostSortedArray(int length);

 public:
  ArrayGenerator();
  void FillWithRandom(std::vector<std::vector<int>>& arr);
  static void FillWithReversed(std::vector<std::vector<int>>& arr);
  void FillWithAlmostSorted(std::vector<std::vector<int>>& arr);
  void LongFillWithRandom(std::vector<std::vector<int>>& arr);
  static void LongFillWithReversed(std::vector<std::vector<int>>& arr);
  void LongFillWithAlmostSorted(std::vector<std::vector<int>>& arr);
};
#endif  // ARRAYGENERATOR_H
