project(server)
cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(gRPC REQUIRED)

find_program(_PROTOBUF_PROTOC protoc)
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

add_executable(server calculator_service.cpp add.grpc.pb.cc add.grpc.pb.h add.pb.cc add.pb.h)
add_executable(client calculator_client.cpp add.grpc.pb.cc add.grpc.pb.h add.pb.cc add.pb.h)

target_link_libraries(server gRPC::grpc++ gRPC::grpc protobuf::libprotobuf)
target_link_libraries(client gRPC::grpc++ gRPC::grpc protobuf::libprotobuf)