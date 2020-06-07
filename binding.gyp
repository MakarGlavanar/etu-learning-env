{
  "targets": [
    { 
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "include_dirs" : [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "target_name": "etu_le_core",
      "sources": [
        "core/models/test/test.hpp",
        "core/models/test/test.cpp",
        "core-node-bus/test/makeTest.hpp",
        "core-node-bus/test/makeTest.cpp",
        "core-node-bus/exports.cpp"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ]
}
