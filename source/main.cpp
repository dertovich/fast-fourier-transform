#include "../include/Fourier_Transform.h"

int main() {
    std::ifstream file("/FFT/data/example_2.json");
    if (!file) {
        std::cerr << "Failed to open file /FFT/data/example_2.json" << std::endl;
        std::cout << "Example of the correct path to JSON-file: '/example/example_1.json'" << std::endl;
        return 1;
    }

    json jsonData;
    file >> jsonData;

    std::vector<std::complex<double>> input;

    for (const auto& value : jsonData) {
        double real = value["re"];
        double imag = value["im"];
        input.emplace_back(real, imag);
    }

    int length = input.size();

    FastFourierTransform fft(length);

    std::vector<std::complex<double>> output = fft.forwardTransform(input);

    std::cout << "Result forward Fourier Transform:" << std::endl;
    for (const auto& value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<std::complex<double>> original = fft.inverseTransform(output);

    std::cout << "Result inverse Fourier Transform:" << std::endl;
    for (const auto& value : original) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    double error = fft.calculateError(input, original);
    std::cout << "Calculate error: " << error << std::endl;

    return 0;
}
