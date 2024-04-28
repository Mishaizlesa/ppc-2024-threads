// Copyright 2024 Lesnikov Nikita
#pragma once

#include <string>
#include <vector>

#include "core/task/include/task.hpp"

std::vector<int> getRandomVector(int sz);
bool isMapsEqual(const std::vector<int>& map1, const std::vector<int>& map2);

class TestOMPTaskSequential : public ppc::core::Task {
 public:
  explicit TestOMPTaskSequential(std::shared_ptr<ppc::core::TaskData> taskData_)
      : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<uint8_t> _source;
  std::vector<int> _result;
  uint32_t _m = 0;
  uint32_t _n = 0;
  uint32_t _numObjects = 0;
};

class TestOMPTaskParallel : public ppc::core::Task {
 public:
  explicit TestOMPTaskParallel(std::shared_ptr<ppc::core::TaskData> taskData_, std::string ops_)
      : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<uint8_t> _source;
  std::vector<int> _result;
  uint32_t _m = 0;
  uint32_t _n = 0;
  uint32_t _numObjects = 0;
};
