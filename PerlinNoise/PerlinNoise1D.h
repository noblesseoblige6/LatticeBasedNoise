#pragma once
#include<vector>

class PerlinNoise1D
{
  private:
    int range;
    std::vector<double> gradients;
  protected:
    int octarveNum;
    double persistence;
    std::vector<double> pixelVal;
    std::vector<int> permutations;

    double sCurve(double);
    double interpolate(double);
    double lerp(double, double, double);
    double random(int);
    double noiseAt(double);
  public:
    PerlinNoise1D();
    ~PerlinNoise1D();
    void setRange(int);
    void setOcterve(int);
    void setPersistence(double);
    void generate();
    double get(int);
};
