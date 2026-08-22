# BezierGeometry

A lightweight, header-only C++ library for Bézier curves and fundamental geometric operations.

The project focuses on the mathematical and geometric representation of Bézier curves while remaining completely independent of any rendering framework. It is designed for graphics programming, creative coding, animation systems, game development, and other applications that require curve mathematics.

---

## Features

### `Evaluate(t)`

Returns the position of a point on a cubic Bézier curve.

$$
B(t) = (1-t)^3 P_0 + 3(1-t)^2 t P_1 + 3(1-t)t^2 P_2 + t^3 P_3
$$

---

### `Derivative(t)`

Returns the first derivative of the curve, representing its instantaneous direction and rate of change.

$$
B'(t) = 3(1-t)^2(P_1-P_0) + 6(1-t)t(P_2-P_1) + 3t^2(P_3-P_2)
$$

---

### `Tangent(t)`

Returns the normalized tangent vector of the curve.

$$
T(t) = \frac{B'(t)}{|B'(t)|}
$$

---

### `Angle(t)`

Returns the tangent angle relative to the positive X-axis in degrees.

$$
\theta = atan2(T_y, T_x)
$$

The angle is converted from radians to degrees:

$$
\theta_{degrees} = \theta_{radians} \frac{180}{\pi}
$$

---

### `SecondDerivative(t)`

Returns the second derivative of the curve.

$$
B''(t) = 6(1-t)(P_2-2P_1+P_0) + 6t(P_3-2P_2+P_1)
$$

---

### `Curvature(t)`

Returns the curvature of the curve.

$$
\kappa = \frac{x'y''-y'x''}{(x'^2+y'^2)^{3/2}}
$$

For 3D curves:

$$
\kappa =
\frac{
\left| B'(t) \times B''(t) \right|
}{
\left| B'(t) \right|^3
}
$$
---

### `Vector2D::Length()`

Returns the magnitude of a 2D vector.

$$
|v| = \sqrt{x^2+y^2}
$$

---

### `Vector2D::Normalize()`

Converts a vector into a unit vector while preserving its direction.

$$
\hat{v} = \frac{v}{|v|}
$$

Zero-length vectors are handled safely.

---

### `Vector3D::Length()`

Returns the magnitude of a 3D vector.

$$
|v| = \sqrt{x^2+y^2+z^2}
$$

---

### `Vector3D::Normalize()`

Converts a 3D vector into a unit vector while preserving its direction.

$$
\hat{v} = \frac{v}{|v|}
$$

Zero-length vectors are handled safely.

---

### `CrossProduct()`

Returns the cross product of two 3D vectors.

$$
A \times B =
(A_yB_z-A_zB_y,\;
A_zB_x-A_xB_z,\;
A_xB_y-A_yB_x)
$$

---

### Control Point Access

- `setP0()`, `setP1()`, `setP2()`, `setP3()` — Update individual control points.
- `getP0()`, `getP1()`, `getP2()`, `getP3()` — Retrieve the current control points.

---

## Design

The library intentionally separates **geometry** from **rendering**.

It contains only mathematical and geometric operations and does not depend on any rendering framework or graphics API.

This allows the same geometry to be used with different rendering systems — or without a renderer at all.

---

## Current Scope

The current implementation supports **2D and 3D cubic Bézier curves** and their fundamental geometric properties.

---

## Future Plans

Planned features for future versions:

- Arc Length calculation
- Constant-speed traversal
- De Casteljau subdivision
- Bounding Box calculation
- Curve-Line intersection
- Curve-Curve intersection
- Unit tests
- CMake support

---

## Contributing

Have an idea, suggestion, or improvement?

Feel free to open an issue or submit a pull request. Feedback and contributions are welcome and can help improve the project and shape its future development.