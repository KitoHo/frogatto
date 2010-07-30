#ifndef CUSTOM_OBJECT_CALLABLE_HPP_INCLUDED
#define CUSTOM_OBJECT_CALLABLE_HPP_INCLUDED

#include <map>
#include <vector>

#include "formula_callable_definition.hpp"

enum CUSTOM_OBJECT_PROPERTY {
	CUSTOM_OBJECT_CONSTS,
	CUSTOM_OBJECT_TYPE,
	CUSTOM_OBJECT_ACTIVE,
	CUSTOM_OBJECT_TIME_IN_ANIMATION,
	CUSTOM_OBJECT_TIME_IN_ANIMATION_DELTA,
	CUSTOM_OBJECT_LEVEL,
	CUSTOM_OBJECT_ANIMATION,
	CUSTOM_OBJECT_HITPOINTS,
	CUSTOM_OBJECT_MAX_HITPOINTS,
	CUSTOM_OBJECT_MASS,
	CUSTOM_OBJECT_LABEL,
	CUSTOM_OBJECT_X,
	CUSTOM_OBJECT_Y,
	CUSTOM_OBJECT_Z,
	CUSTOM_OBJECT_ZORDER,
	CUSTOM_OBJECT_PREVIOUS_Y,
	CUSTOM_OBJECT_X1,
	CUSTOM_OBJECT_X2,
	CUSTOM_OBJECT_Y1,
	CUSTOM_OBJECT_Y2,
	CUSTOM_OBJECT_W,
	CUSTOM_OBJECT_H,
	CUSTOM_OBJECT_MIDPOINT_X,
	CUSTOM_OBJECT_MIDPOINT_Y,
	CUSTOM_OBJECT_SOLID_RECT,
	CUSTOM_OBJECT_IMG_W,
	CUSTOM_OBJECT_IMG_H,
	CUSTOM_OBJECT_FRONT,
	CUSTOM_OBJECT_BACK,
	CUSTOM_OBJECT_CYCLE,
	CUSTOM_OBJECT_FACING,
	CUSTOM_OBJECT_UPSIDE_DOWN,
	CUSTOM_OBJECT_UP,
	CUSTOM_OBJECT_DOWN,
	CUSTOM_OBJECT_VELOCITY_X,
	CUSTOM_OBJECT_VELOCITY_Y,
	CUSTOM_OBJECT_ACCEL_X,
	CUSTOM_OBJECT_ACCEL_Y,
	CUSTOM_OBJECT_VARS,
	CUSTOM_OBJECT_TMP,
	CUSTOM_OBJECT_GROUP,
	CUSTOM_OBJECT_ROTATE,
	CUSTOM_OBJECT_ME,
	CUSTOM_OBJECT_SELF,
	CUSTOM_OBJECT_RED,
	CUSTOM_OBJECT_GREEN,
	CUSTOM_OBJECT_BLUE,
	CUSTOM_OBJECT_ALPHA,
	CUSTOM_OBJECT_TEXT_ALPHA,
	CUSTOM_OBJECT_DAMAGE,
	CUSTOM_OBJECT_HIT_BY,
	CUSTOM_OBJECT_DISTORTION,
	CUSTOM_OBJECT_IS_STANDING,
	CUSTOM_OBJECT_NEAR_CLIFF_EDGE,
	CUSTOM_OBJECT_DISTANCE_TO_CLIFF,
	CUSTOM_OBJECT_SLOPE_STANDING_ON,
	CUSTOM_OBJECT_UNDERWATER,
	CUSTOM_OBJECT_WATER_BOUNDS,
	CUSTOM_OBJECT_WATER_OBJECT,
	CUSTOM_OBJECT_DRIVER,
	CUSTOM_OBJECT_IS_HUMAN,
	CUSTOM_OBJECT_INVINCIBLE,
	CUSTOM_OBJECT_SOUND_VOLUME,
	CUSTOM_OBJECT_DESTROYED,
	CUSTOM_OBJECT_IS_STANDING_ON_PLATFORM,
	CUSTOM_OBJECT_STANDING_ON,
	CUSTOM_OBJECT_FRAGMENT_SHADERS,
	CUSTOM_OBJECT_VERTEX_SHADERS,
	CUSTOM_OBJECT_SHADER,
	CUSTOM_OBJECT_VARIATIONS,
	CUSTOM_OBJECT_ATTACHED_OBJECTS,
	CUSTOM_OBJECT_CALL_STACK,
	CUSTOM_OBJECT_LIGHTS,
	CUSTOM_OBJECT_SOLID_DIMENSIONS_IN,
	CUSTOM_OBJECT_SOLID_DIMENSIONS_NOT_IN,
	CUSTOM_OBJECT_COLLIDE_DIMENSIONS_IN,
	CUSTOM_OBJECT_COLLIDE_DIMENSIONS_NOT_IN,
	CUSTOM_OBJECT_BRIGHTNESS,
	CUSTOM_OBJECT_CURRENT_GENERATOR,
	CUSTOM_OBJECT_TAGS,
	CUSTOM_OBJECT_DRAW_AREA,
	CUSTOM_OBJECT_ACTIVATION_AREA,
	CUSTOM_OBJECT_ALWAYS_ACTIVE,
	CUSTOM_OBJECT_FALL_THROUGH_PLATFORMS,
	CUSTOM_OBJECT_HAS_FEET,
	CUSTOM_OBJECT_X_SCHEDULE,
	CUSTOM_OBJECT_Y_SCHEDULE,
	CUSTOM_OBJECT_ROTATION_SCHEDULE,
	CUSTOM_OBJECT_SCHEDULE_SPEED,
	CUSTOM_OBJECT_CTRL_UP,
	CUSTOM_OBJECT_CTRL_DOWN,
	CUSTOM_OBJECT_CTRL_LEFT,
	CUSTOM_OBJECT_CTRL_RIGHT,
	CUSTOM_OBJECT_CTRL_ATTACK,
	CUSTOM_OBJECT_CTRL_JUMP,
	CUSTOM_OBJECT_CTRL_TONGUE,
	NUM_CUSTOM_OBJECT_PROPERTIES
};

class custom_object_callable : public game_logic::formula_callable_definition
{
public:
	static const custom_object_callable& instance();

	static int get_key_slot(const std::string& key);

	custom_object_callable();

	int get_slot(const std::string& key) const;
	entry* get_entry(int slot);
	const entry* get_entry(int slot) const;
	int num_slots() const { return NUM_CUSTOM_OBJECT_PROPERTIES; }
};

#endif
