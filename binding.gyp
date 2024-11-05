{
  "targets": [
    {
      "target_name": "addon",
      "product_dir": "<(module_root_dir)/resources",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "src-cpp/main.cc",
        "src-cpp/utils.cc",
        # "src-cpp/metrosquare/*.cpp",
#         "src-cpp/metrosquare/eml_rand_mt19937ar.cpp",
# "src-cpp/metrosquare/eml_rand_mt19937ar_stateful.cpp",
# "src-cpp/metrosquare/find.cpp",
# # "src-cpp/metrosquare/minOrMax.cpp",
# "src-cpp/metrosquare/metrosquare.cpp",
# "src-cpp/metrosquare/metrosquare_data.cpp",
# "src-cpp/metrosquare/metrosquare_initialize.cpp",
# "src-cpp/metrosquare/metrosquare_terminate.cpp",
# "src-cpp/metrosquare/my_error_square.cpp",
# "src-cpp/metrosquare/rand.cpp",
# "src-cpp/metrosquare/run_main.cpp",

"src-cpp/metrosquare/eml_rand_mt19937ar.cpp",
"src-cpp/metrosquare/eml_rand_mt19937ar_stateful.cpp",
"src-cpp/metrosquare/find.cpp",
"src-cpp/metrosquare/metrosquare.cpp",
"src-cpp/metrosquare/metrosquare_data.cpp",
"src-cpp/metrosquare/metrosquare_initialize.cpp",
"src-cpp/metrosquare/metrosquare_terminate.cpp",
"src-cpp/metrosquare/minOrMax.cpp",
"src-cpp/metrosquare/my_error_square.cpp",
"src-cpp/metrosquare/prediction_POS.cpp",
"src-cpp/metrosquare/prediction_my_error.cpp",
"src-cpp/metrosquare/probability_PIMC.cpp",
"src-cpp/metrosquare/rand.cpp",
"src-cpp/metrosquare/rtGetInf.cpp",
"src-cpp/metrosquare/rtGetNaN.cpp",
"src-cpp/metrosquare/rt_nonfinite.cpp",
"src-cpp/metrosquare/run_main.cpp",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions": [
        ['OS=="mac"', {
            'cflags+': ['-fvisibility=hidden'],
            'xcode_settings': {
              'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
            }
        }]
      ]
    }
  ]
}
