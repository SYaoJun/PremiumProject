#include <iostream>
#include <grpcpp/grpcpp.h>
#include "add.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculator::Calculator;
using calculator::AddRequest;
using calculator::AddResponse;

class CalculatorServiceImpl final : public Calculator::Service {
public:
    Status Add(ServerContext* context, const AddRequest* request, AddResponse* response) override {
        int result = request->operand1() + request->operand2();
        response->set_result(result);
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50052");
    CalculatorServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
