#include "glm_utils.hpp"

namespace glm_utils {

glm::mat4 identity_matrix(1.0f);
glm::mat4 zero_matrix(0.0f);

glm::vec3 zero(0, 0, 0);
glm::vec3 one(1, 1, 1);
glm::vec3 x(1, 0, 0);
glm::vec3 y(0, 1, 0);
glm::vec3 z(0, 0, 1);

/*
 * the direction vector between a and b is b - a, then we want to go halway across this so (b - a) * 0.5
 * and then add this to a to obtain (a + b) * 0.5
 */
glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b) { return (a + b) * 0.5f; }

glm::vec3 linearly_interpolate(const glm::vec3 &a, const glm::vec3 &b, float t) { return (1 - t) * a + t * b; }

} // namespace glm_utils
