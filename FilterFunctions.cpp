//various functions to modify the map in some way

std::vector<std::vector<float>> bound_filter(std::vector<std::vector<float>> input_map, int width, int height, float min, float max) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    float current_max = -10000000,
          current_min =  10000000;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            if (input_map[j][i] < current_min) current_min = input_map[j][i];
            if (input_map[j][i] > current_max) current_max = input_map[j][i];

        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = map(input_map[j][i], current_min, current_max, min, max);

        }
    }

    return final_map;

}

std::vector<std::vector<float>> inversion_filter(std::vector<std::vector<float>> input_map, int width, int height) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = input_map[j][i] * -1;

        }
    }

    return final_map;

}