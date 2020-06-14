#include "SPA_MjeracVremena.h"

void SPA::MjeracVremena::Start() {
    this->begin = std::chrono::high_resolution_clock::now();
}

void SPA::MjeracVremena::End() {
    this->end = std::chrono::high_resolution_clock::now();
}

double SPA::MjeracVremena::Count() {
    auto len = std::chrono::duration_cast<std::chrono::microseconds>(this->end - this->begin).count();
    return len;
}

double SPA::MjeracVremena::CountMilis() {
    auto len = std::chrono::duration_cast<std::chrono::milliseconds>(this->end - this->begin).count();
    return len;
}
