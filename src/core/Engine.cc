#define WEBVIEW_IMPLEMENTATION
#include "Engine.h"
#include <iostream>
#include <stdlib.h>

n8o::Engine::Engine() {
    std::cout << "Engine initializing" << std::endl;
}

n8o::Engine::~Engine() {
    std::cout << "Engine destructing" << std::endl;
}

int n8o::Engine::init(){
    this->webview.title = "welcome";
    this->webview.height = 400;
    this->webview.width = 300;

    webview_init(&this->webview);

    this->loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
    uv_loop_init(this->loop);
    uv_run(this->loop, UV_RUN_DEFAULT);
    return 0;
}

int n8o::Engine::run() {
    while(webview_loop(&this->webview, 1)==0);
    return 0;
}
