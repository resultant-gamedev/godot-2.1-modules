/*************************************************************************/
/*  light_2d.h                                                           */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2017 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef LIGHT_2D_H
#define LIGHT_2D_H

#include "scene/2d/node_2d.h"

class Light2D : public Node2D {

	OBJ_TYPE(Light2D, Node2D);

public:
	enum Mode {
		MODE_ADD,
		MODE_SUB,
		MODE_MIX,
		MODE_MASK,
	};

private:
	RID canvas_light;
	bool enabled;
	bool editor_only;
	bool shadow;
	Color color;
	Color shadow_color;
	float height;
	float _scale;
	float energy;
	int z_min;
	int z_max;
	int layer_min;
	int layer_max;
	int item_mask;
	int item_shadow_mask;
	int shadow_buffer_size;
	float shadow_esm_multiplier;
	Mode mode;
	Ref<Texture> texture;
	Vector2 texture_offset;

	void _update_light_visibility();

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	virtual void edit_set_pivot(const Point2 &p_pivot);
	virtual Point2 edit_get_pivot() const;
	virtual bool edit_has_pivot() const;

	void set_enabled(bool p_enabled);
	bool is_enabled() const;

	void set_editor_only(bool p_editor_only);
	bool is_editor_only() const;

	void set_texture(const Ref<Texture> &p_texture);
	Ref<Texture> get_texture() const;

	void set_texture_offset(const Vector2 &p_offset);
	Vector2 get_texture_offset() const;

	void set_color(const Color &p_color);
	Color get_color() const;

	void set_height(float p_height);
	float get_height() const;

	void set_energy(float p_energy);
	float get_energy() const;

	void set_texture_scale(float p_scale);
	float get_texture_scale() const;

	void set_z_range_min(int p_min_z);
	int get_z_range_min() const;

	void set_z_range_max(int p_max_z);
	int get_z_range_max() const;

	void set_layer_range_min(int p_min_layer);
	int get_layer_range_min() const;

	void set_layer_range_max(int p_max_layer);
	int get_layer_range_max() const;

	void set_item_mask(int p_mask);
	int get_item_mask() const;

	void set_item_shadow_mask(int p_mask);
	int get_item_shadow_mask() const;

	void set_mode(Mode p_mode);
	Mode get_mode() const;

	void set_shadow_enabled(bool p_enabled);
	bool is_shadow_enabled() const;

	void set_shadow_buffer_size(int p_size);
	int get_shadow_buffer_size() const;

	void set_shadow_esm_multiplier(float p_multiplier);
	float get_shadow_esm_multiplier() const;

	void set_shadow_color(const Color &p_shadow_color);
	Color get_shadow_color() const;

	virtual Rect2 get_item_rect() const;

	String get_configuration_warning() const;

	Light2D();
	~Light2D();
};

VARIANT_ENUM_CAST(Light2D::Mode);

#endif // LIGHT_2D_H
