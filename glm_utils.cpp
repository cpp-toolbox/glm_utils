#include "glm_utils.hpp"

/*
 * the direction vector between a and b is b - a, then we want to go halway across this so (b - a) * 0.5
 * and then add this to a to obtain (a + b) * 0.5
 */
glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b) { return (a + b) * 0.5f; }
