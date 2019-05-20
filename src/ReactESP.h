#ifndef _ReactESP_H
#define _ReactESP_H

#include <functional>

typedef std::function<void()> react_callback;

class ReactESP {

    public:
        ReactESP(const react_callback cb) { app = this; }

        void onRepeat(int count, const std::function <void ()>& f) {};

        static ReactESP* app;
};


extern ReactESP app;

#endif