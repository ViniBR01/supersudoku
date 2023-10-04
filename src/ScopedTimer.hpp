#pragma once

#include <chrono>
#include <iostream>

class ScopedTimer
{
public:
  using ClockType = std::chrono::steady_clock;

  ScopedTimer(const char* func);
  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer(ScopedTimer&&) = delete;
  auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
  auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;

  ~ScopedTimer();
  
private:
  const char* function_name_{};
  const ClockType::time_point start_{};
};
