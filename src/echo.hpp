#pragma once

#include <string>
#include <string_view>

#include <userver/components/component_list.hpp>

namespace shbr_devops_cpp {

    std::string MakeEcho(std::string_view name);

    void AppendEcho(userver::components::ComponentList &component_list);

} // namespace shbr_devops_cpp
