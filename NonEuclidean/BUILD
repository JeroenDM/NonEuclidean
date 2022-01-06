CC_FLAGS = [
    '-std=c++17',
    '-Wall',
]

cc_library(
    name = "vector",
    hdrs = ["Vector.h"],
    visibility = ["//tutorial:__pkg__"],
    copts = CC_FLAGS,
)

cc_library(
    name = "core",
    hdrs = ["GameHeader.h", "Camera.h", "Collider.h", "Sphere.h"],
    srcs = ["Camera.cpp", "Collider.cpp",],
    deps = ["vector"],
    visibility = ["//tutorial:__pkg__"],
    copts = CC_FLAGS,
)

cc_library(
    name = "rendering",
    hdrs = ["Mesh.h", "Shader.h", "Texture.h", "Resources.h"],
    srcs = ["Mesh.cpp", "Shader.cpp", "Texture.cpp", "Resources.cpp"],
    deps = ["vector", "core"],
    visibility = ["//tutorial:__pkg__"],
    copts = CC_FLAGS,
)

cc_library(
    name = "objects",
    hdrs = ["Object.h", "House.h", "Floorplan.h", "Portal.h", "Pillar.h"],
    srcs = ["Object.cpp"],
    deps = ["vector", "core", "rendering"],
    visibility = ["//tutorial:__pkg__"],
    copts = CC_FLAGS,
)