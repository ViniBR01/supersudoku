#pragma once

#include <chrono>
#include <iostream>

class ScopedTimer
{
public:
  using ClockType = std::chrono::steady_clock;

  ScopedTimer(const char* func) : function_name_{func}, start_{ClockType::now()} {}

  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer(ScopedTimer&&) = delete;
  auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
  auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;

  ~ScopedTimer() {
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

private:
  const char* function_name_{};
  const ClockType::time_point start_{};
};
