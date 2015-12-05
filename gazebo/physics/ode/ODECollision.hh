/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_PHYSICS_ODECOLLISION_HH_
#define _GAZEBO_PHYSICS_ODECOLLISION_HH_

#include "ode/ode.h"

#include "gazebo/common/CommonTypes.hh"

#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/physics/Collision.hh"
#include "gazebo/physics/ode/ODETypes.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    // Forward declare private data class.
    class ODECollisionPrivate;

    /// \brief Base class for all ODE collisions.
    class GZ_PHYSICS_VISIBLE ODECollision : public Collision
    {
      /// \brief Constructor.
      /// \param[in] _link Parent Link
      public: explicit ODECollision(LinkPtr _parent);

      /// \brief Destructor.
      public: virtual ~ODECollision();

      // Documentation inherited.
      public: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited.
      public: virtual void Fini();

      /// \brief Set the encapsulated collsion object.
      /// \param[in] _collisionId ODE id of the collision object.
      /// \param[in] _placeable True to make the object movable.
      public: void SetCollision(dGeomID _collisionId, bool _placeable);

      /// \brief Return the collision id.
      /// \return The collision id.
      public: dGeomID GetCollisionId() const;

      /// \brief Get the ODE collision class.
      /// \return The ODE collision class.
      public: int GetCollisionClass() const;

      // Documentation inherited.
      public: virtual void OnPoseChange();

      // Documentation inherited.
      public: virtual void SetCategoryBits(unsigned int bits);

      // Documentation inherited.
      public: virtual void SetCollideBits(unsigned int bits);

      // Documentation inherited.
      public: virtual math::Box GetBoundingBox() const;

      /// \brief Get the collision's space ID
      /// \return The collision's space ID
      public: dSpaceID GetSpaceId() const;

      /// \brief Set the collision's space ID
      /// \param[in] _spaceid ID of an ODE collision space.
      public: void SetSpaceId(dSpaceID _spaceid);

      /// \brief Similar to Collision::GetSurface, but provides dynamically
      ///        casted pointer to ODESurfaceParams.
      /// \return Dynamically casted pointer to ODESurfaceParams.
      public: ODESurfaceParamsPtr GetODESurface() const;

      /// \brief Used when this is static to set the posse.
      private: void OnPoseChangeGlobal();

      /// \brief Used when this is not statis to set the posse.
      private: void OnPoseChangeRelative();

      /// \brief Empty pose change callback.
      private: void OnPoseChangeNull();

      /// \internal
      /// \brief Private data pointer.
      private: std::shared_ptr<ODECollisionPrivate> dataPtr;
    };
  }
}
#endif
