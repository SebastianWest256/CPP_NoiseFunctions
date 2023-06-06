float randomFloat(float min, float max) {
    float random = ((float)rand()) / (float)RAND_MAX;
    float range = max - min;
    return (random * range) + min;
}

uint32_t getColor(uint8_t red, uint8_t green, uint8_t blue) {
    return (red << 16) | (green << 8) | blue;
}

float lerp(float start, float end, float t) {
    return start + t * (end - start);
}


