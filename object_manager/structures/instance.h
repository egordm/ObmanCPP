//
// Created by egordm on 08-09-19.
//

#pragma once

#include <phpcpp.h>

namespace object_manager::structures {
    struct Instance {
        Php::Value value;

        Instance() {}

        Instance(const Instance &instance) : value(instance.value) {}

        Instance(const Php::Value &value) : value(value) {}
    };
}
