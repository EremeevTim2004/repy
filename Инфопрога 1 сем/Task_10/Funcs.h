uint64_t n_double_factorial(uint64_t n) { //
    if (n == 0 || n == 1) { //
        return 1;
    }
    return n * n_double_factorial(n - 2);
}

uint64_t combinations(uint64_t m, uint64_t n) { //
    if (n == m || n == 0) { //
        return 1;
    }
    return combinations(m - 1, n - 1) + combinations(m - 1, n);
}

std::string dec_to_bin(uint64_t x) { //
    std::string res;
    if (x == 0) {
        return res;
    }

    bool next = x % 2;
    if (next == 0) {
        res = "0";
    } else {
        res = "1";
    }

    if (x < 0) {
        return std::string("-") + dec_to_bin( -x / 2) + res;
    }
    return dec_to_bin(x / 2) + res;
}

void print_with_offset(char what, uint64_t offset, uint64_t count) { //
    for (uint64_t i = 0; i < offset; i++) {
        std::cout << " ";
    }
    for (uint64_t i = 0; i < count; i++) {
        std::cout << what;
    }
    std::cout << "\n";
}

void print_spruce(uint64_t depth, uint64_t offset = 0) {
    if (depth == 0) {
        return;
    }
    print_spruce(depth - 1, offset + 1);
    for (uint64_t r = 0; r < depth + 1; r++) {
        print_with_offset('*', offset + depth - r, 1 + r * 2);
    }
}