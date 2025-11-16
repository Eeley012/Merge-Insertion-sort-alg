#ifndef SORTTESTER_H
#define SORTTESTER_H
#include "ArrayGenerator.h"
#include <map>
class SortTester {
 private:
  ArrayGenerator arrayGenerator = ArrayGenerator();
  int logging{};

 public:
  static void clearScreen();
  std::map<size_t, long long> StandartMergeTheRandomData();
  std::map<size_t, long long> StandartMergeTheReversedData();
  std::map<size_t, long long> StandartMergeTheAlmostSortedData();
  std::map<size_t, long long> InsertMergeTheRandomData();
  std::map<size_t, long long> InsertMergeTheReversedData();
  std::map<size_t, long long> InsertMergeTheAlmostSortedData();
  std::vector<std::tuple<int, size_t, long long>> ThresholdInsertMergeTheRandomData();
  std::vector<std::tuple<int, size_t, long long>> ThresholdInsertMergeTheReversedData();
  std::vector<std::tuple<int, size_t, long long>> ThresholdInsertMergeTheAlmostSortedData();
};
#endif  // SORTTESTER_H
