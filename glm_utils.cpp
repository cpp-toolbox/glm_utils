#include "glm_utils.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>
#include <ostream>

namespace glm_utils {

glm::mat4 identity_matrix(1.0f);
glm::mat4 zero_matrix(0.0f);

glm::vec3 zero_R3(0, 0, 0);
glm::vec3 one_R3(1, 1, 1);
glm::vec2 zero_R2(0, 0);
glm::vec2 oen_R2(1, 1);
glm::vec3 x(1, 0, 0);
glm::vec3 y(0, 1, 0);
glm::vec3 z(0, 0, 1);

/*
 * the direction vector between a and b is b - a, then we want to go halway across this so (b - a) * 0.5
 * and then add this to a to obtain (a + b) * 0.5
 */
glm::vec3 get_midpoint(const glm::vec3 &a, const glm::vec3 &b) { return (a + b) * 0.5f; }

glm::vec3 linearly_interpolate(const glm::vec3 &a, const glm::vec3 &b, float t) { return (1 - t) * a + t * b; }

glm::vec3 rotate_vector_to_align_with_forward(const glm::vec3 &forward, const glm::vec3 &to_be_rotated) {
    glm::vec3 canonical_forward = glm::vec3(0.0f, 0.0f, -1.0f);

    // Normalize to ensure valid rotation
    glm::vec3 norm_forward = glm::normalize(forward);
    glm::vec3 norm_canonical = glm::normalize(canonical_forward);

    // Compute the quaternion that rotates `forward` to `canonical_forward`
    glm::quat rotation = glm::rotation(norm_forward, norm_canonical);

    // Rotate the target vector by this quaternion
    glm::vec3 rotated_target = rotation * to_be_rotated;

    return rotated_target;
}

glm::vec2 rotate_vector_to_align_with_forward(const glm::vec2 &forward, const glm::vec2 &to_be_rotated) {
    glm::vec2 canonical_forward = glm::vec2(0.0f, -1.0f);

    glm::vec2 norm_forward = glm::normalize(forward);
    glm::vec2 norm_canonical = glm::normalize(canonical_forward);

    // Compute angle between forward and canonical
    float angle = glm::orientedAngle(norm_forward, norm_canonical); // signed angle in radians

    // Rotate the target vector by this angle
    float cos_a = glm::cos(angle);
    float sin_a = glm::sin(angle);

    glm::mat2 rotation_matrix = glm::mat2(cos_a, -sin_a, sin_a, cos_a);

    return rotation_matrix * to_be_rotated;
}

} // namespace glm_utils
