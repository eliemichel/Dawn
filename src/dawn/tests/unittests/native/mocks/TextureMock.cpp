// Copyright 2022 The Dawn Authors
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

#include "dawn/tests/unittests/native/mocks/TextureMock.h"

namespace dawn::native {

TextureMock::TextureMock(DeviceMock* device,
                         const TextureDescriptor* descriptor,
                         TextureBase::TextureState state)
    : TextureBase(device, descriptor, state) {
    ON_CALL(*this, DestroyImpl).WillByDefault([this] { this->TextureBase::DestroyImpl(); });
}

TextureMock::~TextureMock() = default;

TextureViewMock::TextureViewMock(TextureBase* texture, const TextureViewDescriptor* descriptor)
    : TextureViewBase(texture, descriptor) {
    ON_CALL(*this, DestroyImpl).WillByDefault([this] { this->TextureViewBase::DestroyImpl(); });
}

TextureViewMock::~TextureViewMock() = default;

}  // namespace dawn::native
