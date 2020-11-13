// Copyright 2020 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SRC_AST_TEST_HELPER_H_
#define SRC_AST_TEST_HELPER_H_

#include <memory>
#include <utility>

#include "gtest/gtest.h"

namespace tint {
namespace ast {

/// Helper class for testing
template <typename BASE>
class TestHelperBase : public BASE {
 public:
  TestHelperBase() {}
  ~TestHelperBase() = default;

  /// @return a `std::unique_ptr` to a new `T` constructed with `args`
  /// @param args the arguments to forward to the constructor for `T`
  template <typename T, typename... ARGS>
  std::unique_ptr<T> create(ARGS&&... args) {
    return std::make_unique<T>(std::forward<ARGS>(args)...);
  }
};
using TestHelper = TestHelperBase<testing::Test>;

template <typename T>
using TestParamHelper = TestHelperBase<testing::TestWithParam<T>>;

}  // namespace ast
}  // namespace tint

#endif  // SRC_AST_TEST_HELPER_H_
