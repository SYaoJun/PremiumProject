# grpc和protobuf的简单实践
1. add.proto是定义远程调用函数的格式，请求体和响应体分别是什么。
2. calculator_service.cpp作为服务端，需要实现具体add函数。在正常工作时需要监听不同客户端发来的请求。
3. calculator_client.cpp作为客户端，需要往对应的服务端请求函数执行的结果。
## 跨语言
- 用Python实现的代码作为客户端
## 注意
add.proto相关的文件需要重新生成，可能跟protoc的版本有关
## 编译命令
```sh
# C++ Client
protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` add.proto
protoc -I=. --cpp_out=. add.proto
# Python Client
pip install grpcio-tools
python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. add.proto
```