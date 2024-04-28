# grpc和protobuf的简单实践
1. add.proto是定义远程调用函数的格式，请求体和响应体分别是什么。
2. calculator_service.cpp作为服务端，需要实现具体add函数。在正常工作时需要监听不同客户端发来的请求。
3. calculator_client.cpp作为客户端，需要往对应的服务端请求函数执行的结果。