//
// Created by natha on 10/07/2021.
//

#pragma once

#include "E3D_device.hpp"
#include "E3D_model.hpp"

#include <string>
#include <vector>
#include <assert.h>

namespace E3D {

    struct PipelineConfigInfo {
        PipelineConfigInfo(const PipelineConfigInfo&) = delete;
        PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        std::vector<VkDynamicState> dynamicStateEnables;
        VkPipelineDynamicStateCreateInfo dynamicStateInfo;
        VkPipelineLayout pipelineLayout = 0;//= nullptr;
        VkRenderPass renderPass = 0;//= nullptr;
        uint32_t subpass = 0;
    };

    class Pipeline {
    public:
        Pipeline(Device& device,
                 const std::string& vertFilepath,
                 const std::string& fragFilepath,
                 const PipelineConfigInfo& configInfo);
        ~Pipeline();

        Pipeline(const Pipeline&) = delete;
        Pipeline& operator=(const Pipeline&) = delete;

        void bind(VkCommandBuffer commandBuffer);

        static void defaultPipelineConfigInfo(PipelineConfigInfo& configInfo);

    private:
        static std::vector<char> readFile(const std::string& filename);
        void createGraphicsPipeline(const std::string& vertFilepath,
                                    const std::string& fragFilepath,
                                    const PipelineConfigInfo& configInfo);
        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        Device& m_device;
        VkPipeline m_graphicsPipeline;
        VkShaderModule m_vertShaderModule;
        VkShaderModule m_fragShaderModule;
    };
}  // namespace E3D
