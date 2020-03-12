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

#ifndef SRC_WRITER_WGSL_GENERATOR_IMPL_H_
#define SRC_WRITER_WGSL_GENERATOR_IMPL_H_

#include <sstream>
#include <string>

#include "src/ast/entry_point.h"
#include "src/ast/import.h"
#include "src/ast/module.h"
#include "src/ast/type/alias_type.h"
#include "src/ast/type/type.h"
#include "src/ast/variable.h"

namespace tint {
namespace writer {
namespace wgsl {

/// Implementation class for WGSL generator
class GeneratorImpl {
 public:
  /// Constructor
  GeneratorImpl();
  ~GeneratorImpl();

  /// Generates the result data
  /// @param module the module to generate
  /// @returns true on successful generation; false otherwise
  bool Generate(const ast::Module& module);

  /// @returns the result data
  std::string result() const { return out_.str(); }

  /// @returns the error from the generator
  std::string error() const { return error_; }

  /// Handles generating an alias
  /// @param alias the alias to generate
  /// @returns true if the alias was emitted
  bool EmitAliasType(const ast::type::AliasType* alias);
  /// Handles generating an entry_point command
  /// @param ep the entry point
  /// @returns true if the entry point was emitted
  bool EmitEntryPoint(const ast::EntryPoint* ep);
  /// Handles generating an import command
  /// @param import the import to generate
  /// @returns true if the import was emitted
  bool EmitImport(const ast::Import* import);
  /// Handles generating type
  /// @param type the type to generate
  /// @returns true if the type is emitted
  bool EmitType(ast::type::Type* type);
  /// Handles generating a variable
  /// @param var the variable to generate
  /// @returns true if the variable was emitted
  bool EmitVariable(ast::Variable* var);
  /// Handles generating variable decorations
  /// @param var the decorated variable
  /// @returns true if the variable decoration was emitted
  bool EmitVariableDecorations(ast::DecoratedVariable* var);

 private:
  std::ostringstream out_;
  std::string error_;
};

}  // namespace wgsl
}  // namespace writer
}  // namespace tint

#endif  // SRC_WRITER_WGSL_GENERATOR_IMPL_H_
