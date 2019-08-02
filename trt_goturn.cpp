#include "trt_goturn.h"

#include <iostream>

class Logger : public nvinfer1::ILogger           
{
    void log(Severity severity, const char* msg) override
    {
        // suppress info-level messages
        if (severity != Severity::kINFO)
            std::cout << msg << std::endl;
    }
} gLogger;

int main()
{
    nvinfer1::IBuilder* builder = nvinfer1::createInferBuilder(gLogger);
    nvinfer1::INetworkDefinition* network = builder->createNetwork();

    nvcaffeparser1::ICaffeParser* parser = nvcaffeparser1::createCaffeParser();

    /*for (auto& s : outputs)
    {
        network->markOutput(*blobNameToTensor->find(s.c_str()));
    }*/
}
