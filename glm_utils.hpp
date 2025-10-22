#ifndef GLM_UTILS_HPP
#define GLM_UTILS_HPP

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <string>

#include "sbpt_generated_includes.hpp"

namespace glm_utils {

extern glm::mat4 identity_matrix;
extern glm::mat4 zero_matrix;

extern glm::vec3 zero_R3;
extern glm::vec3 one_R3;
extern glm::vec2 zero_R2;
extern glm::vec2 one_R2;
extern glm::vec3 one;
extern glm::vec3 x;
extern glm::vec3 y;
extern glm::vec3 z;

glm::vec3 parse_vec3(const std::string &s);
glm::vec2 parse_vec2(const std::string &s);

glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b);
glm::vec3 linearly_interpolate(const glm::vec3 &a, const glm::vec3 &b, float t);
glm::vec3 rotate_vector_to_align_with_forward(const glm::vec3 &forward, const glm::vec3 &to_be_rotated);
glm::vec2 rotate_vector_to_align_with_forward(const glm::vec2 &forward, const glm::vec2 &to_be_rotated);

} // namespace glm_utils

#endif // GLM_UTILS_HPP
