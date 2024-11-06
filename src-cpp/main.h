#ifndef MAIN_H
#define MAIN_H

#include <napi.h>

Napi::Value probabilityPIMC(const Napi::CallbackInfo &info);

Napi::Value calculator(const Napi::CallbackInfo &info);


// Napi::Value MyFunction2(const Napi::CallbackInfo& info);

#endif
