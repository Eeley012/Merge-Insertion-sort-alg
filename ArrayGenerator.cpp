#include <random>
#include <vector>
#include "ArrayGenerator.h"

std::vector<int> ArrayGenerator::RandomArray(const int length) {
  std::uniform_int_distribution<int> dist(0, 100000 - length);
  const int start = dist(generator);
  return {arr.begin() + start, arr.begin() + start + length};
}
std::vector<int> ArrayGenerator::ReversedArray(const int length) {
  std::vector<int> result(length);
  for (int i = 0; i < length; i++) {
    result[i] = length - 1 - i;
  }
  return result;
}
std::vector<int> ArrayGenerator::AlmostSortedArray(const int length) {
  std::vector<int> result(length);
  for (int i = 0; i < length; i++) {
    result[i] = i;
  }
  int index2;
  for (int i = 0; i < length / 80; i++) {
    int index1 = distribution(generator) % length;
    do {
      index2 = distribution(generator) % length;
    } while (index1 == index2);
    std::swap(result[index1], result[index2]);
  }
  return result;
}

ArrayGenerator::ArrayGenerator() {
  seed = rd();
  generator.seed(seed);
  for (int& i : arr) {
    i = distribution(generator);
  }
}
void ArrayGenerator::FillWithRandom(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 100; i <= 100000; i += 100) {
    arr[index++] = RandomArray(i);
  }
}
void ArrayGenerator::FillWithReversed(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 100; i <= 100000; i += 100) {
    arr[index++] = ReversedArray(i);
  }
}
void ArrayGenerator::FillWithAlmostSorted(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 100; i <= 100000; i += 100) {
    arr[index++] = AlmostSortedArray(i);
  }
}

void ArrayGenerator::LongFillWithRandom(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 10000; i <= 100000; i += 100) {
    arr[index++] = RandomArray(i);
  }
}
void ArrayGenerator::LongFillWithReversed(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 10000; i <= 100000; i += 100) {
    arr[index++] = ReversedArray(i);
  }
}
void ArrayGenerator::LongFillWithAlmostSorted(std::vector<std::vector<int>>& arr) {
  int index = 0;
  for (int i = 10000; i <= 100000; i += 100) {
    arr[index++] = AlmostSortedArray(i);
  }
}