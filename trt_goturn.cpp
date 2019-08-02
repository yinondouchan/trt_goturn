#include "trt_goturn.h"

#include <iostream>

using namespace nvinfer1;
using namespace nvcaffeparser1;

class Logger : public ILogger           
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
    IBuilder* builder = createInferBuilder(gLogger);
    INetworkDefinition* network = builder->createNetwork();

    //ICaffeParser* parser = createCaffeParser();

    for (auto& s : outputs)
    {
        network->markOutput(*blobNameToTensor->find(s.c_str()));
    }
}
