// Copyright 2024 Zhatkin Vyacheslav
#pragma once

#ifndef TASKS_STL_ZHATKIN_V_TRAPEZOID_METHOD_INCLUDETRAPEZOID_METHOD_TBB_HPP_
#define TASKS_STL_ZHATKIN_V_TRAPEZOID_METHOD_INCLUDETRAPEZOID_METHOD_TBB_HPP_

#include <cmath>
#include <functional>
#include <future>
#include <memory>
#include <numeric>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include "core/task/include/task.hpp"

class ZhatkinTaskTBBSequential : public ppc::core::Task {
 public:
  explicit ZhatkinTaskTBBSequential(std::shared_ptr<ppc::core::TaskData> taskData_,
                                    std::function<double(double, double)> func)
      : Task(std::move(taskData_)), f(std::move(func)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::function<double(double, double)> f;
  double lowerx{}, upperx{}, lowery{}, uppery{}, res = 0.0;
  int nx{}, ny{};
};

double trapezoidal_integral(const std::function<double(double, double)>& f, double lowerx, double upperx, double lowery,
                            double uppery, int nx, int ny);

class ZhatkinTaskSTL : public ppc::core::Task {
 public:
  explicit ZhatkinTaskSTL(std::shared_ptr<ppc::core::TaskData> taskData_, std::function<double(double, double)> func)
      : Task(std::move(taskData_)), f(std::move(func)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::function<double(double, double)> f;
  double lowerx{}, upperx{}, lowery{}, uppery{}, res = 0.0;
  int nx{}, ny{};
};

double trapezoidal_integralSTL(const std::function<double(double, double)>& f, double lowerx, double upperx,
                               double lowery, double uppery, int nx, int ny);

#endif  // TASKS_STL_ZHATKIN_V_TRAPEZOID_METHOD_INCLUDETRAPEZOID_METHOD_TBB_HPP_
