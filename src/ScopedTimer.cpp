#include <chrono>
#include <iostream>

#include "ScopedTimer.hpp"

using ClockType = std::chrono::steady_clock;

ScopedTimer::ScopedTimer(const char* func) : function_name_{func}, start_{ClockType::now()} {}

ScopedTimer::~ScopedTimer() {
  using namespace std::chrono;
  auto stop = ClockType::now();
  auto duration = (stop - start_);
  auto ns = duration_cast<nanoseconds>(duration).count();
  if (ns < 3000)
    std::cout << ns << " ns " << function_name_ << '\n';
  else if (ns < 3000000)
    std::cout << ns/1000 << " us " << function_name_ << '\n';
  else
    std::cout << ns/1000000 << " ms " << function_name_ << '\n';
}
