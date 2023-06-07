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

//applys a blur to the map, this can be done "better" with a neighbor vector but this is easier to write and debug 
std::vector<std::vector<float>> blur_filter(std::vector<std::vector<float>> input_map, int width, int height, int iterations) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int k = 0; k < iterations; k++) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                if (i == 0 && j == 0) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j + 1][i + 1] + input_map[j + 1][i]) / 4.0;
                }
                else if (i == 0 && j == width - 1) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j - 1][i] + input_map[j - 1][i + 1]) / 4.0;
                }
                else if (i == 0 && j != 0 && j != width - 1) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j + 1][i + 1] + input_map[j + 1][i] + input_map[j - 1][i] + input_map[j - 1][i + 1]) / 6.0;
                }
                else if (i == height - 1 && j == 0) {
                    final_map[j][i] = (input_map[j][i] + input_map[j + 1][i] + input_map[j + 1][i - 1] + input_map[j][i - 1]) / 4.0;
                }
                else if (i == height - 1 && j == width - 1) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i - 1] + input_map[j - 1][i - 1] + input_map[j - 1][i]) / 4.0;
                }
                else if (i == height - 1 && j != 0 && j != width - 1) {
                    final_map[j][i] = (input_map[j][i] + input_map[j + 1][i] + input_map[j + 1][i - 1] + input_map[j][i - 1] + input_map[j - 1][i - 1] + input_map[j - 1][i]) / 6.0;
                }
                else if (i != 0 && i != height - 1 && j == 0) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j + 1][i + 1] + input_map[j + 1][i] + input_map[j + 1][i - 1] + input_map[j][i - 1]) / 6.0;
                }
                else if (i != 0 && i != height - 1 && j == width - 1) {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j][i - 1] + input_map[j - 1][i - 1] + input_map[j - 1][i] + input_map[j - 1][i + 1]) / 6.0;
                }
                else {
                    final_map[j][i] = (input_map[j][i] + input_map[j][i + 1] + input_map[j + 1][i + 1] + input_map[j + 1][i] + input_map[j + 1][i - 1] + input_map[j][i - 1] + input_map[j - 1][i - 1] + input_map[j - 1][i] + input_map[j - 1][i + 1]) / 9.0;
                }

            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                input_map[j][i] = final_map[j][i];
            }
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