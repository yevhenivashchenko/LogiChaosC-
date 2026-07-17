#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// 1. Base interface for the transformation stage
class ITransformationStage {
public:
    virtual ~ITransformationStage() = default;
    // Method to apply the transformation
    virtual void forward(std::vector<uint8_t>& data) = 0;
    // Method to reverse the transformation
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
    
    // For XOR, the reverse operation is XOR itself
    void backward(std::vector<uint8_t>& data) override {
        for (auto& byte : data) byte ^= key; 
    }
};

// 3. Pipeline Manager (ChaosLayer)
class ChaosLayer {
    std::vector<std::unique_ptr<ITransformationStage>> stages;
public:
    // Add a new transformation stage to the pipeline
    void addStage(std::unique_ptr<ITransformationStage> stage) {
        stages.push_back(std::move(stage));
    }

    // Apply all transformations in the defined order
    void transform(std::vector<uint8_t>& data) {
        for (auto& stage : stages) stage->forward(data);
    }

    // Restore data by running transformations in reverse order (LIFO)
    void restore(std::vector<uint8_t>& data) {
        for (auto it = stages.rbegin(); it != stages.rend(); ++it) {
            (*it)->backward(data);
        }
    }
};

// 4. Demonstration of functionality
int main() {
    std::vector<uint8_t> data = {'H', 'e', 'l', 'l', 'o'};

    ChaosLayer pipeline;
    pipeline.addStage(std::make_unique<XORStage>(0xAA)); // Adding XOR stage

    // Process output
    std::cout << "Original: ";
    for (char c : data) std::cout << c;

    pipeline.transform(data);
    std::cout << "\nObfuscated (hex): ";
    for (uint8_t b : data) std::cout << std::hex << (int)b << " ";

    pipeline.restore(data);
    std::cout << "\nRestored: ";
    for (uint8_t b : data) std::cout << (char)b;
    std::cout << std::endl;

    return 0;
}
