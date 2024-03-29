#include <iostream>
#include <string>

// Klasa produktu
class Computer {
public:
    void setCPU(const std::string& cpu) {
        cpu_ = cpu;
    }

    void setMemory(const std::string& memory) {
        memory_ = memory;
    }

    void setStorage(const std::string& storage) {
        storage_ = storage;
    }

    void display() {
        std::cout << "CPU: " << cpu_ << std::endl;
        std::cout << "Memory: " << memory_ << std::endl;
        std::cout << "Storage: " << storage_ << std::endl;
    }

private:
    std::string cpu_;
    std::string memory_;
    std::string storage_;
};

// Interfejs budowniczego
class ComputerBuilder {
public:
    virtual void buildCPU(const std::string& cpu) = 0;
    virtual void buildMemory(const std::string& memory) = 0;
    virtual void buildStorage(const std::string& storage) = 0;
    virtual Computer getResult() = 0;
};

// Konkretny budowniczy
class DesktopComputerBuilder : public ComputerBuilder {
public:
    DesktopComputerBuilder() {
        computer_ = Computer();
    }

    void buildCPU(const std::string& cpu) override {
        computer_.setCPU(cpu);
    }

    void buildMemory(const std::string& memory) override {
        computer_.setMemory(memory);
    }

    void buildStorage(const std::string& storage) override {
        computer_.setStorage(storage);
    }

    Computer getResult() override {
        return computer_;
    }

private:
    Computer computer_;
};

// Dyrektor
class ComputerAssembler {
public:
    Computer assembleComputer(ComputerBuilder& builder) {
        builder.buildCPU("Intel i7");
        builder.buildMemory("16GB");
        builder.buildStorage("512GB SSD");
        return builder.getResult();
    }
};

int main() {
    DesktopComputerBuilder desktopBuilder;
    ComputerAssembler assembler;

    // Konfiguracja 1
    Computer desktop1 = assembler.assembleComputer(desktopBuilder);
    std::cout << "Desktop Computer Configuration 1 (Król):" << std::endl;
    desktop1.display();

    // Konfiguracja 2
    desktopBuilder = DesktopComputerBuilder(); // Resetujemy buildera
    Computer desktop2 = assembler.assembleComputer(desktopBuilder);
    std::cout << "Desktop Computer Configuration 2 (Król):" << std::endl;
    desktop2.display();

    return 0;
}
