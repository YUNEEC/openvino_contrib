// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <cuda_operation_base.hpp>
#include <memory>
#include <transformer/nodes/fused_convolution.hpp>

#include "convolution_components/convolution_components.hpp"

namespace CUDAPlugin {

class FusedConvolutionOp : public OperationCuDnn {
public:
    using NodeOp = nodes::FusedConvolution;

    template <typename TOperation>
    FusedConvolutionOp(const CreationContext& context,
                       const TOperation& node,
                       IndexCollection&& inputIds,
                       IndexCollection&& outputIds);

    void Execute(const InferenceRequestContext& context,
                 Inputs inputTensors,
                 Outputs outputTensors,
                 const Workbuffers& workbuffers) const override;
    
    WorkbufferRequest GetWorkBufferRequest() const override;

    void InitSharedImmutableWorkbuffers(const IOperationExec::Buffers&) override {}
    const WorkbufferIds& GetWorkbufferIds() const override;
    WorkbufferStatus SetWorkbufferIds(WorkbufferIds&& workbufferIds) override;

    using ArgIndices = Convolution::Details::FusedConvolutionIndices;

private:
    void CreateImpl(const CreationContext& context, const ngraph::Node& node);
    std::unique_ptr<IOperationExec> impl_;
};

}  // namespace CUDAPlugin
