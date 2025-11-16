#ifndef MERGEINSERT_H
#define MERGEINSERT_H
#include <iostream>
#include <vector>
void insertionSort(std::vector<int>& ints);
void Merge(std::vector<int>& ints, size_t left, size_t mid, size_t right);
void MergeInsertSort(std::vector<int>& ints, size_t left, size_t right, int thereshold);
#endif  // MERGEINSERT_H
