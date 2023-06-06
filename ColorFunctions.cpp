//functions for coloring maps, expects values from -1 to 1

int standard_color(float value) {

	if (value > 0.2) {
		return 0x00FF00;
	}
	else if(value > 0.15 && value <= 0.2) {
		return 0xFFFF00;
	}
	else {
		return 0x0000FF;
	}

}