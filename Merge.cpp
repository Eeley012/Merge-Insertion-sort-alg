#include <vector>
#include <cstdint>
#include "Merge.h"
void MergeS(std::vector<int>& ints, const size_t left, const size_t mid, const size_t right) {
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
void MergeSort(std::vector<int>& ints, const size_t left, const size_t right) {
  if (left < right) {
    const size_t mid = left + (right - left) / 2;
    MergeSort(ints, left, mid);
    MergeSort(ints, mid + 1, right);
    MergeS(ints, left, mid, right);
  }
}
