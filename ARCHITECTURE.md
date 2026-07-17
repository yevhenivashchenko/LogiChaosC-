graph TD
    subgraph "Input Processing"
    Input[Raw Data] --> PM[Pipeline Manager]
    end

    subgraph "Transformation Pipeline (ChaosLayer)"
    PM --> S1[Stage 1: Obfuscator A]
    S1 --> S2[Stage 2: Obfuscator B]
    S2 --> Sn[Stage N: Obfuscator N]
    end

    subgraph "Output"
    Sn --> Output[Obfuscated/Chaotic Data]
    end

    subgraph "Restoration Path"
    Output --> RPM[Reverse Pipeline Manager]
    RPM --> RSn[Reverse Stage N]
    RSn --> RS2[Reverse Stage B]
    RS2 --> RS1[Reverse Stage A]
    RS1 --> Restored[Original Data]
    end


......work_cod///////
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// 1. Base interface for a transformation stage
class ITransformationStage {
public:
    virtual ~ITransformationStage() = default;
    virtual void forward(std::vector<uint8_t>& data) = 0;
    virtual void backward(std::vector<uint8_t>& data) = 0;
};

// 2. Example implementation: XOR Stage
class XORStage : public ITransformationStage {
    uint8_t key;
public:
    explicit XORStage(uint8_t k) : key(k) {}
    void forward(std::vector<uint8_t>& data) override {
        for (auto& byte : data) byte ^= key;
    }
    void backward(std::vector<uint8_t>& data) override {
        forward(data); // For XOR, the inverse operation is XOR itself
    }
};

// 3. Pipeline Manager (ChaosLayer)
class ChaosLayer {
    std::vector<std::unique_ptr<ITransformationStage>> stages;
public:
    void addStage(std::unique_ptr<ITransformationStage> stage) {
        stages.push_back(std::move(stage));
    }

    void transform(std::vector<uint8_t>& data) {
        for (auto& stage : stages) stage->forward(data);
    }

    void restore(std::vector<uint8_t>& data) {
        // Iterate in reverse order (LIFO - Last-In, First-Out)
        for (auto it = stages.rbegin(); it != stages.rend(); ++it) {
            (*it)->backward(data);
        }
    }
};

// 4. Demonstration of functionality
int main() {
    // Initial data
    std::vector<uint8_t> data = {'H', 'e', 'l', 'l', 'o'};

    ChaosLayer pipeline;
    pipeline.addStage(std::make_unique<XORStage>(0xAA)); // Adding XOR stage

    // Process
    std::cout << "Original: ";
    for (char c : data) std::cout << c;

    pipeline.transform(data);
    std::cout << "\nObfuscated: ";
    for (uint8_t b : data) std::cout << std::hex << (int)b << " ";

    pipeline.restore(data);
    std::cout << "\nRestored: ";
    for (uint8_t b : data) std::cout << (char)b;

    return 0;
}
