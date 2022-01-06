CC_FLAGS = [
    '-std=c++17',
    '-Wall',
]

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//NonEuclidean:vector",
        "//NonEuclidean:rendering",
    ],
    data = ["//assets:Meshes/bunny.obj"],
    linkopts = [
        # first tree are the result of `pkg-config --libs glew`
        "-lGLEW",
        "-lGLU",
        "-lGL",
        "-lglut",
    ],
    copts = CC_FLAGS,
)
