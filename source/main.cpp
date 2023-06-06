#include "../include/Fourier_Transform.h"


int main() {
    setlocale(LC_ALL, "Russian");

    try {
        FastFourierTransform fft(8);

        std::vector<std::complex<double>> input = { 1.0, 2.0, 3.0, 4.0, 4.0, 3.0, 2.0, 1.0 };
        std::vector<std::complex<double>> output = fft.forwardTransform(input);

        std::cout << "Результат прямого преобразования Фурье:" << std::endl;
        for (const auto& value : output) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        std::vector<std::complex<double>> original = fft.inverseTransform(output);

        std::cout << "Результат обратного преобразования Фурье:" << std::endl;
        for (const auto& value : original) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        double error = fft.calculateError(input, original);
        std::cout << "Ошибка: " << error << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}