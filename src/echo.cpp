#include "echo.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace shbr_devops_cpp {
    namespace {
        class Echo final : public userver::server::handlers::HttpHandlerBase {
            public:
              static constexpr std::string_view kName = "handler-echo";

              using HttpHandlerBase::HttpHandlerBase;

              std::string HandleRequestThrow(const userver::server::http::HttpRequest &request, userver::server::request::RequestContext &) const override {
                auto& response = request.GetHttpResponse();
                response.SetHeader("X-Shbr-Lang", "cpp");
                return shbr_devops_cpp::MakeEcho(request.GetRequestPath().substr(1));
              }
        };

    } // namespace

    std::string MakeEcho(std::string_view name) {
      auto prefix = std::getenv("PREFIX");
      return fmt::format("{}{}", prefix ? prefix : "", name);
    }

    void AppendEcho(userver::components::ComponentList &component_list) {
      component_list.Append<Echo>();
    }
} // namespace shbr_devops_cpp
