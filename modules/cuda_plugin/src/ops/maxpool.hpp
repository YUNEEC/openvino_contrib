// Copyright (C) 2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <cuda_operation_base.hpp>

#include "pooling_impl.hpp"

namespace CUDAPlugin {

class MaxPoolOp : public OperationCuDnn {
public:
    explicit MaxPoolOp(const CreationContext& context,
                       const std::shared_ptr<ngraph::Node>& node,
                       IndexCollection&& inputIds,
                       IndexCollection&& outputIds);
    void Execute(const InferenceRequestContext& context,
                 Inputs inputTensors,
                 Outputs outputTensors,
                 const Workbuffers& workbuffers) const override;

private:
    PoolingImpl impl_;
};

}  // namespace CUDAPlugin
