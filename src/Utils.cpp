/// @file Utils.cpp
/// @brief Useful functions
/// @author Ivan Fonseca

#include "../inc/Utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(float a, float b) {
    return (a > b) ? b : a;
}

int sign(float num) {
    if (num == 0) {
        return 0;
    }
    return (num > 0) ? 1 : -1;
}

bool contains(const int *arr, const int size, const int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

bool inRange(float val, float min, float max) {
    return val >= min && val <= max;
}

float clamp(float val, float min, float max) {
    if (val < min) {
        return min;
    } else if (val > max) {
        return max;
    } else {
        return val;
    }
}

void itoa(char *str, int num) {
  snprintf(str, sizeof(str), "%d", num);
}

const char *getFilename(const char *path) {
    char delim[2] = "/";
    char *token = strtok((char *) path, delim);
    char *lastToken = (char *) malloc(50);
    
    // Keep looping to end of string
    while (token != NULL) {
        // Store this token in case it was the last one
        snprintf(lastToken, sizeof(lastToken), "%s", token);
        token = strtok(NULL, delim);
    }

    return lastToken;
}
