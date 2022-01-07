CC_FLAGS = [
    '-std=c++17',
    '-Wall',
]

exports_files(["shaders/shader.vert", "shaders/shader.frag"])

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//NonEuclidean:vector",
        "//NonEuclidean:rendering",
    ],
    # "//assets:Meshes/bunny.obj",
    data = ["shaders/shader.vert", "shaders/shader.frag"],
    linkopts = [
        # first tree are the result of `pkg-config --libs glew`
        "-lGLEW",
        "-lGLU",
        "-lGL",
        "-lglut",
    ],
    copts = CC_FLAGS,
)
