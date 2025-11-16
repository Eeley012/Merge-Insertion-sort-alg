#include <iostream>
#include <vector>
#include "MergeInsert.h"

void insertionSort(std::vector<int>& ints) {
  const size_t len = ints.size();
  for (size_t i = 1; i < len; i++) {
    const int key = ints[i];
    int j = i - 1;

    while (j >= 0 && ints[j] > key) {
      ints[j + 1] = ints[j];
      j = j - 1;
    }
    ints[j + 1] = key;
  }
}

void Merge(std::vector<int>& ints, const size_t left, const size_t mid, const size_t right) {
  std::vector<int> copy_left(ints.begin() + static_cast<int64_t>(left), ints.begin() + static_cast<int64_t>(mid) + 1);
  std::vector<int> copy_right(ints.begin() + static_cast<int64_t>(mid) + 1,
                              ints.begin() + static_cast<int64_t>(right) + 1);
  auto left_it = copy_left.begin();
  auto right_it = copy_right.begin();
  auto intervals_it = ints.begin() + static_cast<int64_t>(left);
  while (left_it < copy_left.end() && right_it < copy_right.end()) {
    if (*left_it <= *right_it) {
      *(intervals_it++) = *left_it;
      ++left_it;
    } else {
      *(intervals_it++) = *right_it;
      ++right_it;
    }
  }
  while (left_it < copy_left.end()) {
    *(intervals_it++) = *left_it;
    ++left_it;
  }
  while (right_it < copy_right.end()) {
    *(intervals_it++) = *right_it;
    ++right_it;
  }
}

void MergeInsertSort(std::vector<int>& ints, size_t left, size_t right, int thereshold) {
  if (right - left + 1 <= thereshold) {
    std::vector<int> temp(ints.begin() + left, ints.begin() + right + 1);
    insertionSort(temp);
    std::copy(temp.begin(), temp.end(), ints.begin() + left);
  } else if (left < right) {
    const size_t mid = left + (right - left) / 2;
    MergeInsertSort(ints, left, mid, thereshold);
    MergeInsertSort(ints, mid + 1, right, thereshold);
    Merge(ints, left, mid, right);
  }
}

// int main() {
//   int n;
//   std::cin >> n;
//   std::vector<int> ints(n);
//   for (size_t i = 0; i < n; i++) {
//     std::cin >> ints[i];
//   }
//   MergeInsertSort(ints, 0, n - 1);
//   for (size_t i = 0; i < n; i++) {
//     std::cout << ints[i] << " ";
//   }
//   return 0;
// }
