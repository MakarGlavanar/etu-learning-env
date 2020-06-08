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
        "core/models/task/Task.cpp",
        "core/models/test/Test.cpp",
        "core/services/task/TaskService.cpp",
        "core/services/test/TestService.cpp",
        "core-node-bus/task/TaskDecorator.cpp",
        "core-node-bus/test/TestDecorator.cpp",
        "core-node-bus/exports.cpp"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ]
}
