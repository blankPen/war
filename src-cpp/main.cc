#include <napi.h>
#include "main.h"
#include "metrosquare/run_main.h"
#include "metrosquare/probability_PIMC.h"
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
  // double data[64] = {};
  // for (int i = 0; i < arr.Length(); i++)
  // {
  //   data[i] = arr.Get(i).As<Napi::Number>().DoubleValue();
  // }

  double qb_0 = info[1].As<Napi::Number>();
  double t_known = info[2].As<Napi::Number>();

  // const double data[64] = {
  //   0,
  //   1,
  //   2,
  //   3,
  //   4,
  //   5,
  //   6,
  //   7,
  //   8,
  //   9,
  //   10,
  //   11,
  //   12,
  //   13,
  //   14,
  //   15,
  //   16,
  //   17,
  //   18,
  //   19,
  //   20,
  //   21,
  //   22,
  //   23,
  //   24,
  //   25,
  //   26,
  //   27,
  //   28,
  //   29,
  //   30,
  //   31,
  //   513056,
  //   511467,
  //   509084,
  //   506999,
  //   504824,
  //   503435,
  //   502261,
  //   500356,
  //   498808,
  //   497200,
  //   495673,
  //   493353,
  //   491977,
  //   490700,
  //   489695,
  //   488653,
  //   487494,
  //   486490,
  //   485658,
  //   483827,
  //   481568,
  //   479929,
  //   478701,
  //   476833,
  //   475557,
  //   474178,
  //   472535,
  //   471254,
  //   470171,
  //   468490,
  //   466893,
  //   464795,
  // };
  // double qb_0 = 21600;
  // double t_known = 27;

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
  // run_main(data, qb_0, t_known, &kr, &kb);

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

  // Function Declarations
  // extern void run_main(const double data[64], double qb_0, double t_known,
  //                      const double *kr, const double *kb, const double *c1,
  //                      const double *c2, const double *c3, double *probability,
  //                      double t_data[], int t_size[1], double *qr_0,
  //                      double qtsquare_data[], int qtsquare_size[1],
  //                      double qtfisher_data[], int qtfisher_size[1],
  //                      double *error_code);

  Napi::Object obj = Napi::Object::New(env);

  // 创建一个 Napi::Array
  Napi::Array array = Napi::Array::New(env, 32);

  // 填充数组
  for (uint32_t i = 0; i < 32; i++)
  {
    array.Set(i, t_data[i]);
  }

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

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("probabilityPIMC", Napi::Function::New(env, probabilityPIMC));
  exports.Set("calculator", Napi::Function::New(env, calculator));
  return exports;
}

NODE_API_MODULE(addon, Init)
