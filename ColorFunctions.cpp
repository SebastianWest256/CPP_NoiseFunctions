//functions for coloring pixels, expects a value from -1 to 1, returns an integer representing a color

//colors pixels blue, yellow, and green based on their value
int standard_color(float value) {

	value = (value + 1) * 128;
	return getColor(value, value, value);

}

int basic_terrain_color(float value) {

	if (value > 0.2) {
		return 0x00FF00;
	}
	else if (value > 0.15 && value <= 0.2) {
		return 0xFFFF00;
	}
	else {
		return 0x0000FF;
	}

}