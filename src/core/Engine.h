#ifndef __ENGINE__
#define __ENGINE__

#include <libuv/include/uv.h>
#include "webview/webview.h"

namespace n8o
{
    class Engine
    {
    private:
        int debug;
        struct webview webview;
        uv_loop_t* loop;
        
    public:
        Engine();
        ~Engine();
        int init();
        int run();
    };
} // namespace n8s


#endif