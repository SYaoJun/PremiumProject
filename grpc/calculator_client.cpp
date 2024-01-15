#include <iostream>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "add.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using calculator::Calculator;
using calculator::AddRequest;
using calculator::AddResponse;

class CalculatorClient {
public:
    CalculatorClient(std::shared_ptr<Channel> channel) : stub_(Calculator::NewStub(channel)) {}

    int Add(int operand1, int operand2) {
        AddRequest request;
        request.set_operand1(operand1);
        request.set_operand2(operand2);

        AddResponse response;
        ClientContext context;

        Status status = stub_->Add(&context, request, &response);

        if (status.ok()) {
            return response.result();
        } else {
            std::cout << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

private:
    std::unique_ptr<Calculator::Stub> stub_;
};

int main() {
    CalculatorClient calculator(grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials()));
    
    int result = calculator.Add(10, 20);
    if (result >= 0) {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
