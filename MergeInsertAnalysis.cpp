#include <map>
#include <random>
#include "SortTester.h"
#include <fstream>

void SaveToCSV(const std::string& filename, const std::map<size_t, long long>& data) {
  std::ofstream out(filename);
  out << "size,time\n";
  for (auto& [sz, tm] : data)
    out << sz << "," << tm << "\n";
}

void SaveThresholdToCSV(const std::string& filename, const std::vector<std::tuple<int, size_t, long long>>& data) {
  std::ofstream out(filename);
  out << "threshold,size,time\n";
  for (const auto& [threshold, size, time] : data) {
    out << threshold << "," << size << "," << time << "\n";
  }
}

int main() {
  auto sortTester = SortTester();
  // Стандартный MERGE
  std::map<size_t, long long> MergeRandomData = sortTester.StandartMergeTheRandomData();
  std::map<size_t, long long> MergeReversedData = sortTester.StandartMergeTheReversedData();
  std::map<size_t, long long> MergeAlmostSortedData = sortTester.StandartMergeTheAlmostSortedData();
  SaveToCSV("merge_random.csv", MergeRandomData);
  SaveToCSV("merge_reversed.csv", MergeReversedData);
  SaveToCSV("merge_almost_sorted.csv", MergeAlmostSortedData);

  // Merge + Insertion
  std::map<size_t, long long> InsertMergeRandomData = sortTester.InsertMergeTheRandomData();
  std::map<size_t, long long> InsertMergeReversedData = sortTester.InsertMergeTheReversedData();
  std::map<size_t, long long> InsertMergeAlmostSortedData = sortTester.InsertMergeTheAlmostSortedData();
  SaveToCSV("mergeinsert_random.csv", InsertMergeRandomData);
  SaveToCSV("mergeinsert_reversed.csv", InsertMergeReversedData);
  SaveToCSV("mergeinsert_almost_sorted.csv", InsertMergeAlmostSortedData);

  // порог Insertion
  std::vector<std::tuple<int, size_t, long long>> thresholdRandomData = sortTester.ThresholdInsertMergeTheRandomData();
  std::vector<std::tuple<int, size_t, long long>> thresholdReversedData =
      sortTester.ThresholdInsertMergeTheReversedData();
  std::vector<std::tuple<int, size_t, long long>> thresholdAlmostSortedData =
      sortTester.ThresholdInsertMergeTheAlmostSortedData();
  SaveThresholdToCSV("threshold_random.csv", thresholdRandomData);
  SaveThresholdToCSV("threshold_reversed.csv", thresholdReversedData);
  SaveThresholdToCSV("threshold_almost_sorted.csv", thresholdAlmostSortedData);
  return 0;
}