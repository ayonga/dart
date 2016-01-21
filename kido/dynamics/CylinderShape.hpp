/*
 * Copyright (c) 2013-2015, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Tobias Kunz <tobias@gatech.edu>
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KIDO_DYNAMICS_CYLINDERSHAPE_HPP_
#define KIDO_DYNAMICS_CYLINDERSHAPE_HPP_

#include "kido/dynamics/Shape.hpp"

namespace kido {
namespace dynamics {

class CylinderShape : public Shape {
public:
  // To get byte-aligned Eigen vectors
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /// \brief Constructor.
  CylinderShape(double _radius, double _height);

  /// \brief
  double getRadius() const;

  /// \brief
  void setRadius(double _radius);

  /// \brief
  double getHeight() const;

  /// \brief
  void setHeight(double _height);

  // Documentation inherited.
  void draw(renderer::RenderInterface* _ri = nullptr,
            const Eigen::Vector4d& _color = Eigen::Vector4d::Ones(),
            bool _useDefaultColor = true) const;

  /// \brief Compute volume from given properties
  static double computeVolume(double radius, double height);

  /// \brief Compute moments of inertia of a cylinder
  static Eigen::Matrix3d computeInertia(
      double radius, double height, double mass);

  // Documentation inherited.
  Eigen::Matrix3d computeInertia(double mass) const override;

protected:
  // Documentation inherited.
  void updateVolume() override;

private:
  /// \brief
  void _updateBoundingBoxDim();

  /// \brief
  double mRadius;

  /// \brief Height along z-axis.
  double mHeight;
};

}  // namespace dynamics
}  // namespace kido

#endif  // KIDO_DYNAMICS_CYLINDERSHAPE_HPP_