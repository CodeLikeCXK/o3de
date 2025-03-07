/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <Common/RHI/Factory.h>
#include <Common/RHI/Stubs.h>
#include <Atom/RHI/DispatchRaysIndirectBuffer.h>
#include <Atom/RHI/RayTracingAccelerationStructure.h>
#include <Atom/RHI/RayTracingPipelineState.h>
#include <Atom/RHI/RayTracingShaderTable.h>
#include <Atom/RHI/RayTracingBufferPools.h>
#include <Atom/RHI/TransientAttachmentPool.h>
#include <Atom/RHI/FrameGraphExecuter.h>
#include <Atom/RHI/FrameGraphCompiler.h>
#include <Atom/RHI/PipelineState.h>
#include <Atom/RHI/ShaderResourceGroupPool.h>
#include <Atom/RHI/Fence.h>
#include <Atom/RHI/SwapChain.h>

namespace UnitTest
{
    namespace StubRHI
    {
        using namespace AZ;
        
        Factory::Factory() :
            m_platformName{"UnitTest"}
        {
            RHI::Factory::Register(this);
        }

        Factory::~Factory()
        {
            RHI::Factory::Unregister(this);

            RHI::ResourceInvalidateBus::AllowFunctionQueuing(false);
            RHI::ResourceInvalidateBus::ClearQueuedEvents();
        }

        RHI::Ptr<RHI::Device> Factory::CreateDefaultDevice()
        {
            RHI::PhysicalDeviceList physicalDevices = Get().EnumeratePhysicalDevices();
            AZ_Assert(physicalDevices.size() == 1, "Expected a single physical device.");

            RHI::Ptr<RHI::Device> device = Get().CreateDevice();
            device->Init(RHI::MultiDevice::DefaultDeviceIndex, *physicalDevices[0]);

            return device;
        }

        Name Factory::GetName()
        {
            return m_platformName;
        }

        RHI::APIPriority Factory::GetDefaultPriority()
        {
            return RHI::APIMiddlePriority;
        }

        RHI::APIType Factory::GetType()
        {
            return RHI::APIType(m_platformName.GetStringView());
        }

        bool Factory::SupportsXR() const
        {
            return false;
        }

        RHI::PhysicalDeviceList Factory::EnumeratePhysicalDevices()
        {
            return PhysicalDevice::Enumerate();
        }

        RHI::Ptr<RHI::Device> Factory::CreateDevice()
        {
            return aznew Device;
        }

        RHI::Ptr<RHI::SwapChain> Factory::CreateSwapChain()
        {
            return aznew SwapChain;
        }

        RHI::Ptr<RHI::Fence> Factory::CreateFence()
        {
            return aznew Fence;
        }

        RHI::Ptr<RHI::Buffer> Factory::CreateBuffer()
        {
            return aznew Buffer;
        }

        RHI::Ptr<RHI::BufferView> Factory::CreateBufferView()
        {
            return aznew BufferView;
        }

        RHI::Ptr<RHI::BufferPool> Factory::CreateBufferPool()
        {
            return aznew BufferPool;
        }

        RHI::Ptr<RHI::Image> Factory::CreateImage()
        {
            return aznew Image;
        }

        RHI::Ptr<RHI::ImageView> Factory::CreateImageView()
        {
            return aznew ImageView;
        }

        RHI::Ptr<RHI::ImagePool> Factory::CreateImagePool()
        {
            return aznew ImagePool;
        }

        RHI::Ptr<RHI::StreamingImagePool> Factory::CreateStreamingImagePool()
        {
            return aznew StreamingImagePool;
        }

        RHI::Ptr<RHI::ShaderResourceGroupPool> Factory::CreateShaderResourceGroupPool()
        {
            return aznew ShaderResourceGroupPool;
        }

        RHI::Ptr<RHI::ShaderResourceGroup> Factory::CreateShaderResourceGroup()
        {
            return aznew ShaderResourceGroup;
        }

        RHI::Ptr<RHI::PipelineLibrary> Factory::CreatePipelineLibrary()
        {
            return aznew PipelineLibrary;
        }

        RHI::Ptr<RHI::PipelineState> Factory::CreatePipelineState()
        {
            return aznew PipelineState;
        }

        RHI::Ptr<RHI::Scope> Factory::CreateScope()
        {
            return aznew Scope;
        }

        RHI::Ptr<RHI::FrameGraphCompiler> Factory::CreateFrameGraphCompiler()
        {
            return aznew FrameGraphCompiler;
        }

        RHI::Ptr<RHI::FrameGraphExecuter> Factory::CreateFrameGraphExecuter()
        {
            return aznew FrameGraphExecuter;
        }

        RHI::Ptr<RHI::TransientAttachmentPool> Factory::CreateTransientAttachmentPool()
        {
            return aznew TransientAttachmentPool;
        }

        AZ::RHI::Ptr<AZ::RHI::QueryPool> Factory::CreateQueryPool()
        {
            return aznew QueryPool;
        }

        AZ::RHI::Ptr<AZ::RHI::Query> Factory::CreateQuery()
        {
            return aznew Query;
        }

        AZ::RHI::Ptr<AZ::RHI::IndirectBufferSignature> Factory::CreateIndirectBufferSignature()
        {
            return aznew IndirectBufferSignature;
        }

        AZ::RHI::Ptr<AZ::RHI::IndirectBufferWriter> Factory::CreateIndirectBufferWriter()
        {
            return aznew IndirectBufferWriter;
        }

        AZ::RHI::Ptr<AZ::RHI::RayTracingBufferPools> Factory::CreateRayTracingBufferPools()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }

        AZ::RHI::Ptr<AZ::RHI::RayTracingBlas> Factory::CreateRayTracingBlas()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }

        AZ::RHI::Ptr<AZ::RHI::RayTracingTlas> Factory::CreateRayTracingTlas()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }

        AZ::RHI::Ptr<AZ::RHI::RayTracingPipelineState> Factory::CreateRayTracingPipelineState()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }

        AZ::RHI::Ptr<AZ::RHI::RayTracingShaderTable> Factory::CreateRayTracingShaderTable()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }

        RHI::Ptr<RHI::DispatchRaysIndirectBuffer> Factory::CreateDispatchRaysIndirectBuffer()
        {
            AZ_Assert(false, "Not implemented");
            return nullptr;
        }
    }
}
