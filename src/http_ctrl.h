#pragma once

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

namespace chrmi {
    class HttpCtrl {
    public:
        HttpCtrl() {}
        HttpCtrl(string_t url);

        pplx::task<void> open() { return m_listener.open(); }
        pplx::task<void> close() { return m_listener.close(); }

    private:
        void handle_get(http_request message);
        void handle_put(http_request message);
        void handle_post(http_request message);
        void handle_delete(http_request message);

        http_listener m_listener;
    };
};
