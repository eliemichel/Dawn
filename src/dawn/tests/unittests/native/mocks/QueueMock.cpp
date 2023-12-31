// Copyright 2023 The Dawn Authors
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

#include "dawn/tests/unittests/native/mocks/QueueMock.h"

#include "dawn/tests/unittests/native/mocks/DeviceMock.h"

namespace dawn::native {

QueueMock::QueueMock(DeviceMock* device, const QueueDescriptor* descriptor)
    : QueueBase(device, descriptor) {
    ON_CALL(*this, DestroyImpl).WillByDefault([this] { this->QueueBase::DestroyImpl(); });
}

QueueMock::~QueueMock() = default;

}  // namespace dawn::native
