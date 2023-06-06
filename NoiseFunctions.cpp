//various expirimental noise funcations as well as some non-noise functions

//random values, not a noise function
std::vector<std::vector<float>> random_map(int width, int height, float min, float max) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = randomFloat(min, max);

        }
    }

    return final_map;

}

//gradient along the x-axis, not a noise function
std::vector<std::vector<float>> gradient_map(int width, int height, float min, float max) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = map(j, -1, width, min, max);

        }
    }

    return final_map;

}

//increases the size of the map to the next power of 2 then randomly assigns a value to each index, sums up the values at decreasing intervals at decreasing weights, technically functional but not producing very useful results yet
std::vector<std::vector<float>> weighted_interval_map(int width, int height, float min, float max) {

    std::vector<std::vector<float>> final_map(width, std::vector<float>(height));

    int power = ceil(logarithm(2, width));
    int adjusted_width = pow(2, power);
    int adjusted_height = pow(2, power);

    std::vector<std::vector<float>> start_map(adjusted_width, std::vector<float>(adjusted_height));
    std::vector<std::vector<float>> sum_map(adjusted_width, std::vector<float>(adjusted_height));

    for (int i = 0; i < adjusted_height; i++) {
        for (int j = 0; j < adjusted_width; j++) {

            start_map[i][j] = randomFloat(-1, 1);
            sum_map[i][j] = 0;

        }
    }

    float step;
    for (int k = 0; k < adjusted_height; k++) {
        for (int i = 0; i < power; i++) {
            step = adjusted_width / int(pow(2, i + 1));
            for (int j = 0; j < adjusted_width; j++) {
                sum_map[k][j] += (lerp(start_map[k][int(j - j % int(step))], start_map[k][int(int((j - j % int(step) + step)) % adjusted_width)], (j % int(step)) / step)) / pow(2, i);
            }
        }
    }
    
    for (int i = 0; i < adjusted_height; i++) {
        for (int j = 0; j < adjusted_width; j++) {

            start_map[j][i] = sum_map[i][j];
            sum_map[i][j] = 0;

        }
    }

   for (int k = 0; k < adjusted_height; k++) {
        for (int i = 0; i < power; i++) {
            step = adjusted_width / int(pow(2, i + 1));
            for (int j = 0; j < adjusted_width; j++) {
                sum_map[k][j] += (lerp(start_map[k][int(j - j % int(step))], start_map[k][int(int((j - j % int(step) + step)) % adjusted_width)], (j % int(step)) / step)) / pow(2, i);
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            final_map[j][i] = map(sum_map[j][i],-4,4,-1,1);

        }
    }

    return final_map;

}




