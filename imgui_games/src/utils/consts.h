#pragma once

#include "base.h"

#include <imgui.h>
#include <vector>

const Vect DEFAULT_WORLD_SIZE{ 800.0f, 600.0f };

const std::vector<ImColor> COLORS
{
	{0, 255, 255}, // Aqua
	{0, 0, 0}, // Black 
	{0, 0, 255}, // Blue
	{255, 251, 240}, // Cream
	{128, 128, 128}, // Grey
	{255, 0, 255}, // Fuchsia
	{0, 128, 0}, // Green
	{0, 255, 0}, // Lime green
	{128, 0, 0}, // Maroon
	{0, 0, 128}, // Navy
	{128, 128, 0},	 // Olive green
	{255, 0, 255}, // Purple
	{255, 0, 255}, // Red
	{192, 192, 192}, // Silver
	{0, 128, 128}, // Teal
	{255, 255, 255}, // White
};

