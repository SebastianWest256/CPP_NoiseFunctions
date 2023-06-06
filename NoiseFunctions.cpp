std::vector<std::vector<float>> random_map(int width, int height, float min, float max) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = randomFloat(min, max);

        }
    }

    return final_map;

}




