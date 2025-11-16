#include "SortTester.h"
#include "Merge.h"
#include "ArrayGenerator.h"
#include "MergeInsert.h"
#include <map>

void SortTester::clearScreen() {
  system("clear");
}

std::map<size_t, long long> SortTester::StandartMergeTheRandomData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> random(1000);
  arrayGenerator.FillWithRandom(random);
  for (const auto& i : random) {
    logging++;
    long long avg{};
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeSort(data_copy, 0, i.size() - 1);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      const long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::map<size_t, long long> SortTester::StandartMergeTheReversedData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> reversed(1000);
  arrayGenerator.FillWithReversed(reversed);
  for (const auto& i : reversed) {
    logging++;
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    long long avg{};
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeSort(data_copy, 0, i.size() - 1);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::map<size_t, long long> SortTester::StandartMergeTheAlmostSortedData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> almost_sorted(1000);
  arrayGenerator.FillWithAlmostSorted(almost_sorted);
  for (const auto& i : almost_sorted) {
    logging++;
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    long long avg{};
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeSort(data_copy, 0, i.size() - 1);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::map<size_t, long long> SortTester::InsertMergeTheRandomData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> random(1000);
  arrayGenerator.FillWithRandom(random);
  for (const auto& i : random) {
    logging++;
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    long long avg{};
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeInsertSort(data_copy, 0, i.size() - 1, 15);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::map<size_t, long long> SortTester::InsertMergeTheReversedData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> reversed(1000);
  arrayGenerator.FillWithReversed(reversed);
  for (const auto& i : reversed) {
    logging++;
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    long long avg{};
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeInsertSort(data_copy, 0, i.size() - 1, 15);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::map<size_t, long long> SortTester::InsertMergeTheAlmostSortedData() {
  std::map<size_t, long long> data;
  std::vector<std::vector<int>> almost_sorted(1000);
  arrayGenerator.FillWithAlmostSorted(almost_sorted);
  for (const auto& i : almost_sorted) {
    logging++;
    if (logging % 100 == 0) {
      std::cout << "Выполняется тест № " << logging << " из 6000" << std::endl;
    }
    long long avg{};
    for (int j = 0; j < 10; j++) {
      std::vector<int> data_copy = i;
      auto start = std::chrono::high_resolution_clock::now();
      MergeInsertSort(data_copy, 0, i.size() - 1, 15);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
      avg += msec;
    }
    avg /= 10;
    data[i.size()] = avg;
  }
  return data;
}
std::vector<std::tuple<int, size_t, long long>> SortTester::ThresholdInsertMergeTheRandomData() {
  std::vector<std::tuple<int, size_t, long long>> data(9000);
  int index{};
  std::vector<std::vector<int>> random(1000);
  arrayGenerator.LongFillWithRandom(random);
  const std::vector<int> thereshold{5, 10, 20, 50, 100, 200, 400, 1000, 2000};
  for (const auto& t : thereshold) {
    for (const auto& i : random) {
      logging++;
      if (logging % 100 == 0) {
        std::cout << "Выполняется тест № " << logging << " из 27000" << std::endl;
      }
      long long avg{};
      for (int j = 0; j < 1; j++) {
        std::vector<int> data_copy = i;
        auto start = std::chrono::high_resolution_clock::now();
        MergeInsertSort(data_copy, 0, i.size() - 1, t);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
        avg += msec;
      }
      // avg /= 2;
      data[index++] = std::make_tuple(t, i.size(), avg);
    }
  }
  return data;
}
std::vector<std::tuple<int, size_t, long long>> SortTester::ThresholdInsertMergeTheReversedData() {
  std::vector<std::tuple<int, size_t, long long>> data(9000);
  std::vector<std::vector<int>> reversed(1000);
  int index{};
  arrayGenerator.LongFillWithReversed(reversed);
  const std::vector<int> thereshold{5, 10, 20, 50, 100, 200, 400, 1000, 2000};
  for (const auto& t : thereshold) {
    for (const auto& i : reversed) {
      logging++;
      if (logging % 100 == 0) {
        std::cout << "Выполняется тест № " << logging << " из 27000" << std::endl;
      }
      long long avg{};
      for (int j = 0; j < 1; j++) {
        std::vector<int> data_copy = i;
        auto start = std::chrono::high_resolution_clock::now();
        MergeInsertSort(data_copy, 0, i.size() - 1, t);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
        avg += msec;
      }
      // avg /= 2;
      data[index++] = std::make_tuple(t, i.size(), avg);
    }
  }
  return data;
}
std::vector<std::tuple<int, size_t, long long>> SortTester::ThresholdInsertMergeTheAlmostSortedData() {
  std::vector<std::tuple<int, size_t, long long>> data(9000);
  std::vector<std::vector<int>> almost_sorted(1000);
  int index{};
  arrayGenerator.LongFillWithAlmostSorted(almost_sorted);
  const std::vector<int> thereshold{5, 10, 20, 50, 100, 200, 400, 1000, 2000};
  // std::vector<int> thereshold{5, 10, 20, 30, 50, 90}; //старая версия с маленькими значениями
  for (const auto& t : thereshold) {
    for (const auto& i : almost_sorted) {
      logging++;
      if (logging % 100 == 0) {
        std::cout << "Выполняется тест № " << logging << " из 27000" << std::endl;
      }
      long long avg{};
      for (int j = 0; j < 1; j++) {
        std::vector<int> data_copy = i;
        auto start = std::chrono::high_resolution_clock::now();
        MergeInsertSort(data_copy, 0, i.size() - 1, t);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
        avg += msec;
      }
      // avg /= 2;
      data[index++] = std::make_tuple(t, i.size(), avg);
    }
  }
  return data;
}