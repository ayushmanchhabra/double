#include <stdio.h>
#include <stdlib.h>

// Data set (usually you read from file)
float data[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

// n = 10/2
#define n (sizeof(data) / sizeof(data[0]))

float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

float cost(float w)
{
    float L = 0.0f;
    for (size_t i = 0; i < n; i++)
    {
        // Given input
        float x = data[i][0];
        // Observed output
        float y = w * x;
        // Predicted output
        float t = data[i][1];
        // Difference between observed and predicted output
        float l = y - t;
        // Squared error
        L += l * l;
    }
    // Average error over n inputs
    L /= n;
    return L;
}

int main()
{
    // y = w*x + b
    // weight w is randomly generated
    // bias b is zero in this model
    // 10.0f is arbitrary
    // but should be greater than 0.0f
    float w = rand_float() * 10.0f;
    // Learning rate determines step size of iteration
    // while moving toward minimum of cost function
    // 0.01
    float lr = 1e-1;

    for (size_t i = 0; i < 10; i++)
    {
        // 0.001
        float h = 1e-3;
        // Find direction of jump using limit definition of derivative
        float dw = (cost(w + h) - cost(w)) / h;
        // Find magnitude of jump by multiplying by learning rate
        w -= lr * dw;
    }

    // Model has (almost) inferred the function f(x) = 2*x although it does not know what double means
    // An interesting question is raised but I'll leave that up to the reader to ponder
    printf("Computed Weight: %f\nEstimate double of 10: %f\nSample size: %lu\n", w, w * 10, n);
    return 0;
}