//
// Created by egordm on 08-09-19.
//

#pragma once

#include <unordered_set>
#include "../interfaces/config_interface.h"
#include "../structures/kind_table.hpp"
#include "../wrappers/relations.h"
#include "relations.h"

using namespace object_manager::interface;

namespace object_manager {
    class Config : public ConfigInterface {
    protected:
        std::unordered_map<KindId, KindId> preferences;
        std::unordered_map<KindId, KindId> virtual_types;
        std::unordered_map<KindId, std::unordered_map<std::string, Argument>> arguments;
        std::unordered_map<KindId, std::unordered_map<std::string, Argument>> merged_arguments;
        std::unordered_set<KindId> non_shared_types;

        Relations relations;

    public:
        Config() : relations() {}

        void set_relations(RelationsInterface *relations) override {}

        std::unordered_map<std::string, Argument> *get_arguments(KindId type) override;

        bool is_shared(KindId type) override;

        KindId get_instance_type(KindId instance_type) override;

        KindId get_preference(KindId type) override;

        std::unordered_map<KindId, KindId> &get_virtual_types() override;

        void extend(std::map<std::string, Php::Value> &configuration) override;

        std::unordered_map<KindId, KindId> &get_preferences() override;
    };

}

