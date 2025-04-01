#ifndef GLM_UTILS_HPP
#define GLM_UTILS_HPP

#include <glm/glm.hpp>

namespace glm_utils {

extern glm::mat4 identity_matrix;
extern glm::mat4 zero_matrix;

extern glm::vec3 zero;
extern glm::vec3 one;
extern glm::vec3 x;
extern glm::vec3 y;
extern glm::vec3 z;

glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b);

} // namespace glm_utils

#endif // GLM_UTILS_HPP
