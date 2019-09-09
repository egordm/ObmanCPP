//
// Created by egordm on 08-09-19.
//

#pragma once

#include "../interfaces.h"

using namespace object_manager::interface;

namespace object_manager {
    class Definition : public DefinitionInterface {
    protected:
        ConfigInterface *config;
        std::unordered_map<KindId, std::vector<Parameter>> definitions;

    public:
        Definition(ConfigInterface *config) : config(config) {}

        std::vector<Parameter> get_parameters(KindId kind_id) override;

        std::vector<std::string> get_classes() override;
    };
}
