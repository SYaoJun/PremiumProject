import grpc
import add_pb2
import add_pb2_grpc

def run():
    channel = grpc.insecure_channel('localhost:50052')  # 假设服务器运行在本地的 50051 端口
    stub = add_pb2_grpc.CalculatorStub(channel)
    
    # 构造请求
    request = add_pb2.AddRequest(operand1=10, operand2=20)
    
    # 调用远程函数
    response = stub.Add(request)
    
    print("Sum:", response.result)

if __name__ == '__main__':
    run()
