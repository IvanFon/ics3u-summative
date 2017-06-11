/// @file Utils.h
/// @brief Useful functions
/// @author Ivan Fonseca

#ifndef _INC_UTILS_H
#define _INC_UTILS_H

/// @brief Returns the lowest number
/// @param a The first number to compare
/// @param b The second number to compare
int min(float a, float b);

/// @brief Returns the sign of a number
/// @param num The number to check
/// @return -1, 0 or 1 depending the sign of the number
int sign(float num);
//
/// @brief Checks if an array contains an item
/// @param arr The array to check in
/// @param size The size of the array
/// @param num The number to check the array for
/// @return true if the item is in the array, false otherwise
bool contains(const int *arr, const int size, const int num);

/// @brief Checks if a value is in a given range
/// @param val The value to check
/// @param min The lower bound of the range
/// @param max The upper bound of the range
/// @return true if in range, false otherwise
bool inRange(float val, float min, float max);

/// @brief Clamps or restricts a number to a rainge
/// @param val The value to clamp
/// @param min The lower bound of the range
/// @param max The upper bound of the range
/// @return The clamped value
float clamp(float val, float min, float max);

/// @brief Converts an integer into a string
/// @param str The string to put the integer into
/// @param num The integer to convert
void itoa(char *str, int num);

/// @brief Get filename from a path
/// @param path The path to the file
/// @return The filename
const char *getFilename(const char *path);

#endif
