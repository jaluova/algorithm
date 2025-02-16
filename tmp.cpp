auto diag_sum = [&](auto &diag) {
    for (int i = 1; i < diag.size()) {
        for (int j = 1; i < diag.size(); j++) {
            diag[i][j] += diag[i - 1][j - 1];
        }
    }
};