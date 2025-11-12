#ifndef GLM_UTILS_HPP
#define GLM_UTILS_HPP

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <string>

#include "sbpt_generated_includes.hpp"

namespace glm_utils {

/// @brief Identity matrix (4x4) constant.
extern glm::mat4 identity_matrix;

/// @brief Zero matrix (4x4) constant.
extern glm::mat4 zero_matrix;

/// @brief Zero vector in R³ (3D space).
extern glm::vec3 zero_R3;

/// @brief Unit vector with all components equal to 1 in R³.
extern glm::vec3 one_R3;
extern glm::vec3 minus_one_R3;

/// @brief Zero vector in R² (2D space).
extern glm::vec2 zero_R2;

/// @brief Unit vector with all components equal to 1 in R².
extern glm::vec2 one_R2;
extern glm::vec2 minus_one_R2;

/// @brief Unit vector along the X-axis (1, 0, 0).
extern glm::vec3 x;

/// @brief Unit vector along the Y-axis (0, 1, 0).
extern glm::vec3 y;

/// @brief Unit vector along the Z-axis (0, 0, 1).
extern glm::vec3 z;

template <typename T1, typename T2> glm::vec2 tuple_to_vec2(const std::tuple<T1, T2> &t) {
    return glm::vec2{static_cast<float>(std::get<0>(t)), static_cast<float>(std::get<1>(t))};
}

template <typename T1, typename T2, typename T3> glm::vec3 tuple_to_vec3(const std::tuple<T1, T2, T3> &t) {
    return glm::vec3{static_cast<float>(std::get<0>(t)), static_cast<float>(std::get<1>(t)),
                     static_cast<float>(std::get<2>(t))};
}

template <typename T1, typename T2, typename T3, typename T4>
glm::vec4 tuple_to_vec4(const std::tuple<T1, T2, T3, T4> &t) {
    return glm::vec4{static_cast<float>(std::get<0>(t)), static_cast<float>(std::get<1>(t)),
                     static_cast<float>(std::get<2>(t)), static_cast<float>(std::get<3>(t))};
}

/**
 * @brief Parses a string into a 3D vector (vec3).
 *
 * The input string should be in a format like "x,y,z".
 *
 * @param s Input string representing a 3D vector.
 * @return glm::vec3 Parsed vector.
 */
glm::vec3 parse_vec3(const std::string &s);

/**
 * @brief Parses a string into a 2D vector (vec2).
 *
 * The input string should be in a format like "x,y".
 *
 * @param s Input string representing a 2D vector.
 * @return glm::vec2 Parsed vector.
 */
glm::vec2 parse_vec2(const std::string &s);

/**
 * @brief Computes the midpoint between two 3D points.
 *
 * @param a First point.
 * @param b Second point.
 * @return glm::vec3 Midpoint between a and b.
 */
glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b);

/**
 * @brief Linearly interpolates between two 3D vectors.
 *
 * @param a Start vector.
 * @param b End vector.
 * @param t Interpolation factor in [0, 1].
 * @return glm::vec3 Interpolated vector.
 */
glm::vec3 linearly_interpolate(const glm::vec3 &a, const glm::vec3 &b, float t);

/**
 * @brief Rotates a 3D vector to align with a forward direction.
 *
 * @param forward The target forward direction.
 * @param to_be_rotated The vector to rotate.
 * @return glm::vec3 Rotated vector aligned with forward.
 */
glm::vec3 rotate_vector_to_align_with_forward(const glm::vec3 &forward, const glm::vec3 &to_be_rotated);

/**
 * @brief Rotates a 2D vector to align with a forward direction.
 *
 * @param forward The target forward direction in 2D.
 * @param to_be_rotated The 2D vector to rotate.
 * @return glm::vec2 Rotated vector aligned with forward.
 */
glm::vec2 rotate_vector_to_align_with_forward(const glm::vec2 &forward, const glm::vec2 &to_be_rotated);

} // namespace glm_utils

#endif // GLM_UTILS_HPP
