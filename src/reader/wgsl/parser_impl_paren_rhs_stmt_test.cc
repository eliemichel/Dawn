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

#include "gtest/gtest.h"
#include "src/reader/wgsl/parser_impl.h"
#include "src/reader/wgsl/parser_impl_test_helper.h"

namespace tint {
namespace reader {
namespace wgsl {
namespace {

TEST_F(ParserImplTest, ParenRhsStmt) {
  auto* p = parser("(a + b)");
  auto e = p->paren_rhs_stmt();
  ASSERT_FALSE(p->has_error()) << p->error();
  ASSERT_NE(e, nullptr);
  ASSERT_TRUE(e->IsBinary());
}

TEST_F(ParserImplTest, ParenRhsStmt_MissingLeftParen) {
  auto* p = parser("true)");
  auto e = p->paren_rhs_stmt();
  ASSERT_TRUE(p->has_error());
  ASSERT_EQ(e, nullptr);
  EXPECT_EQ(p->error(), "1:1: expected '('");
}

TEST_F(ParserImplTest, ParenRhsStmt_MissingRightParen) {
  auto* p = parser("(true");
  auto e = p->paren_rhs_stmt();
  ASSERT_TRUE(p->has_error());
  ASSERT_EQ(e, nullptr);
  EXPECT_EQ(p->error(), "1:6: expected ')'");
}

TEST_F(ParserImplTest, ParenRhsStmt_InvalidExpression) {
  auto* p = parser("(if (a() {})");
  auto e = p->paren_rhs_stmt();
  ASSERT_TRUE(p->has_error());
  ASSERT_EQ(e, nullptr);
  EXPECT_EQ(p->error(), "1:2: unable to parse expression");
}

TEST_F(ParserImplTest, ParenRhsStmt_MissingExpression) {
  auto* p = parser("()");
  auto e = p->paren_rhs_stmt();
  ASSERT_TRUE(p->has_error());
  ASSERT_EQ(e, nullptr);
  EXPECT_EQ(p->error(), "1:2: unable to parse expression");
}

}  // namespace
}  // namespace wgsl
}  // namespace reader
}  // namespace tint
