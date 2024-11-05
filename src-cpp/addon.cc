#include <napi.h>

// 函数定义
int add2(int a, int b) {
    return a + b;
}


Napi::Value Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Number num1 = info[0].As<Napi::Number>();
  Napi::Number num2 = info[1].As<Napi::Number>();


  int v = add2(1, 2);
  // Napi::Number sum = Napi::Number::New(env, add2(1, 2) + add(3, 4));
  Napi::Number sum = Napi::Number::New(env, v + num2.DoubleValue());
  return sum;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("add", Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(addon, Init)
