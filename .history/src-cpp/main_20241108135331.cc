#include <napi.h>
#include <stdint.h>
#include "main.h"
#include "metrosquare/run_main.h"
#include "metrosquare/probability_PIMC.h"
#include "metrosquare/prediction_my_error.h"
#include "metrosquare/my_error_square.h"
#include <iostream>

Napi::Array cpp2NapiArray(const Napi::Env &env, double *array, uint32_t length)
{
  // 创建一个长度为32的Napi::Array
  Napi::Array arr = Napi::Array::New(env, length);

  // 遍历数组并设置Napi::Array的每个元素
  for (uint32_t i = 0; i < length; ++i)
  {
    arr.Set(i, array[i]);
  }

  return arr;
}

double *napi2CppDoubleArray(const Napi::Array arr)
{
  size_t length = arr.Length();
  double *data = new double[length];
  for (int i = 0; i < length; i++)
  {
    data[i] = arr.Get(i).As<Napi::Number>().DoubleValue();
  }
  return data;
}

Napi::Value probabilityPIMC(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  double kr = info[0].As<Napi::Number>();
  double kb = info[1].As<Napi::Number>();
  Napi::Array arr = info[2].As<Napi::Array>();
  double t_known = info[3].As<Napi::Number>();
  double *data = napi2CppDoubleArray(arr);
  double num_grid_points_r = std::round(data[32] / 100.0) * 20.0;

  // double kr, double kb, const double data[64],
  //                         double t_known, double num_grid_points_r
  double p = probability_PIMC(kr, kb, data, t_known, num_grid_points_r);
  // return cpp2NapiArray(env, data, 64);
  return Napi::Number::New(env, p);
}

Napi::Value calculator(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  Napi::Array arr = info[0].As<Napi::Array>();

  double *data = napi2CppDoubleArray(arr);
  double qb_0 = info[1].As<Napi::Number>();
  double t_known = info[2].As<Napi::Number>();

  double kr;
  double kb;
  double c1;
  double c2;
  double c3;
  double probability;
  double t_data[32];
  int t_size;
  double qr_0;
  double qtsquare_data[32];
  int qtsquare_size;
  double qtfisher_data[32];
  int qtfisher_size;
  double error_code;

  run_main(
      data, qb_0,
      t_known,
      &kr,
      &kb,
      &c1,
      &c2,
      &c3,
      &probability,
      t_data,
      *(int(*)[1]) & t_size,
      &qr_0,
      qtsquare_data,
      *(int(*)[1]) & qtsquare_size,
      qtfisher_data,
      *(int(*)[1]) & qtfisher_size,
      &error_code);

  double bx1[3] = {c1, c2, c3};
  double bx2[2] = {kr, kb};
  double norm = prediction_my_error(bx1, data, t_known);
  double norm2 = my_error_square(bx2, data, qb_0, t_known);

  // fprintf('本项目模型的二范数：%.3f\n',prediction_my_error([c1,c2,c3],data,t_known))
  // fprintf('兰彻斯特模型的二范数：%.3f\n',my_error_square([kr,kb],data,qb_0,t_known))

  // Function Declarations
  // extern void run_main(const double data[64], double qb_0, double t_known,
  //                      const double *kr, const double *kb, const double *c1,
  //                      const double *c2, const double *c3, double *probability,
  //                      double t_data[], int t_size[1], double *qr_0,
  //                      double qtsquare_data[], int qtsquare_size[1],
  //                      double qtfisher_data[], int qtfisher_size[1],
  //                      double *error_code);

  Napi::Object obj = Napi::Object::New(env);
  obj.Set("kr", kr);
  obj.Set("kb", kb);
  obj.Set("c1", c1);
  obj.Set("c2", c2);
  obj.Set("c3", c3);
  obj.Set("probability", probability);
  obj.Set("t_data", cpp2NapiArray(env, t_data, 32));
  obj.Set("qr_0", qr_0);
  obj.Set("qtsquare_data", cpp2NapiArray(env, qtsquare_data, 32));
  obj.Set("qtfisher_data", cpp2NapiArray(env, qtfisher_data, 32));
  obj.Set("t_size", t_size);
  obj.Set("qtsquare_size", qtsquare_size);
  obj.Set("qtfisher_size", qtfisher_size);
  obj.Set("error_code", error_code);
  obj.Set("norm", norm);
  obj.Set("norm2", norm2);

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("probabilityPIMC", Napi::Function::New(env, probabilityPIMC));
  exports.Set("calculator", Napi::Function::New(env, calculator));
  return exports;
}

NODE_API_MODULE(addon, Init)
