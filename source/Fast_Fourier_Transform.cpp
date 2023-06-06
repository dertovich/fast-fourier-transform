#include "../include/Fourier_Transform.h"

void FastFourierTransform::generateTrigTable() {
    int maxFactor = 5;

    for (int factor = 1; factor <= maxFactor; factor++) {
        int step = trigTable.size() / factor;
        std::vector<std::complex<double>> row(step);

        for (int i = 0; i < step; i++) {
            double angle = -2.0 * PI * i / trigTable.size();
            row[i] = std::polar(1.0, angle * factor);
        }

        trigTable.push_back(row);
    }
}

FastFourierTransform::FastFourierTransform(int length) {
    if (length % 2 != 0 && length % 3 != 0 && length % 5 != 0) {
        throw std::invalid_argument("Длина преобразования должна быть кратной 2, 3 и 5.");
    }

    generateTrigTable();
}

std::vector<std::complex<double>> FastFourierTransform::forwardTransform(const std::vector<std::complex<double>>& input) {
    std::vector<std::complex<double>> output = input;

    int size = output.size();
    if (size <= 1) {
        return output;
    }

    std::vector<std::complex<double>> even(size / 2);
    std::vector<std::complex<double>> odd(size / 2);
    for (int i = 0; i < size / 2; ++i) {
        even[i] = output[2 * i];
        odd[i] = output[2 * i + 1];
    }

    even = forwardTransform(even);
    odd = forwardTransform(odd);

    double angle = 2 * PI / size;
    std::complex<double> w(1);
    std::complex<double> wn(std::cos(angle), std::sin(angle));

    for (int i = 0; i < size / 2; ++i) {
        std::complex<double> temp = w * odd[i];
        output[i] = even[i] + temp;
        output[i + size / 2] = even[i] - temp;
        w *= wn;
    }

    return (output);
}

std::vector<std::complex<double>> FastFourierTransform::inverseTransform(const std::vector<std::complex<double>>& input) {
    std::vector<std::complex<double>> output = input;

    int size = output.size();
    if (size <= 1) {
        return (output);
    }

    std::vector<std::complex<double>> even(size / 2);
    std::vector<std::complex<double>> odd(size / 2);
    for (int i = 0; i < size / 2; ++i) {
        even[i] = output[2 * i];
        odd[i] = output[2 * i + 1];
    }

    even = inverseTransform(even);
    odd = inverseTransform(odd);

    double angle = -2 * PI / size;
    std::complex<double> w(1);
    std::complex<double> wn(std::cos(angle), std::sin(angle));

    for (int i = 0; i < size / 2; ++i) {
        std::complex<double> temp = w * odd[i];
        output[i] = even[i] + temp;
        output[i + size / 2] = even[i] - temp;
        w *= wn;
    }

    for (int i = 0; i < size; ++i) {
        output[i] /= size;
    }

    return (output);
}

double FastFourierTransform::calculateError(const std::vector<std::complex<double>>& input, const std::vector<std::complex<double>>& output) {
    int size = input.size();
    double error = 0.0;

    for (int i = 0; i < size; ++i) {
        double diffReal = std::abs(input[i].real() - output[i].real());
        double diffImag = std::abs(input[i].imag() - output[i].imag());
        error += diffReal + diffImag;
    }

    return (error);
}
