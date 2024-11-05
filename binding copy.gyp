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
        # "src-cpp/metrosquare_cpp/*.cpp",
        "src-cpp/metrosquare_cpp/eml_rand_mt19937ar.cpp",
"src-cpp/metrosquare_cpp/eml_rand_mt19937ar_stateful.cpp",

#include "find.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "minOrMax.h"
#include "my_error_square.h"
#include "rand.h"

"src-cpp/metrosquare_cpp/find.cpp",
# "src-cpp/metrosquare_cpp/minOrMax.cpp",
"src-cpp/metrosquare_cpp/metrosquare.cpp",
"src-cpp/metrosquare_cpp/metrosquare_data.cpp",
"src-cpp/metrosquare_cpp/metrosquare_initialize.cpp",
"src-cpp/metrosquare_cpp/metrosquare_terminate.cpp",
"src-cpp/metrosquare_cpp/my_error_square.cpp",
"src-cpp/metrosquare_cpp/rand.cpp",
"src-cpp/metrosquare_cpp/run_main.cpp",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      # "conditions": [
      #   ['OS=="mac"', {
      #       'cflags+': ['-fvisibility=hidden'],
      #       'xcode_settings': {
      #         'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
      #       }
      #   }]
      # ]
    }
  ]
}
