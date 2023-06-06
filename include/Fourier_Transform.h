#ifndef FOURIER_TRANSFORM_H
#define FOURIER_TRANSFORM_H

#include <vector>
#include <complex>
#include <iostream>
#include <stdexcept>

#define PI 3.141592653589793238462643383279

class FastFourierTransform {
private:
    std::vector<std::vector<std::complex<double>>> trigTable;
    void generateTrigTable();

public:
    FastFourierTransform(int length);

    // Forward and inverse Fourier transform methods
    std::vector<std::complex<double>> forwardTransform(const std::vector<std::complex<double>>& input);
    std::vector<std::complex<double>> inverseTransform(const std::vector<std::complex<double>>& input);

    // 
    double calculateError(const std::vector<std::complex<double>>& input, const std::vector<std::complex<double>>& output);
};

#endif /*FOURIER_TRANSFORM_H*/
