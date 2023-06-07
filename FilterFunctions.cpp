//various functions to modify the map in some way

std::vector<std::vector<float>> inversion_filter(std::vector<std::vector<float>> input_map, int width, int height) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = input_map[j][i] * -1;

        }
    }

    return final_map;

}