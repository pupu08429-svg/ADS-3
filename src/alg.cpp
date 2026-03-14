// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
	uint64_t max_value = 1;
	while (num > 1) {
		if (max_value < num) {
			max_value = num;
		}
		if (num % 2 != 0) {
			num = 3 * num + 1;
		}
		else {
			num = num / 2;
		}
	}
	return max_value;
}

unsigned int collatzLen(uint64_t num) {
	unsigned int k = 1;
	while (num > 1) {
		if (num % 2 != 0) {
			num = 3 * num + 1;
		}
		else {
			num = num / 2;
		}
		k++;
	}
	return k;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
	unsigned int current_len = 0;
	unsigned int max_len = 0;
	uint64_t number = lbound;
	for (uint64_t i = rbound; i >= lbound; i--) {
		current_len = collatzLen(i);
		if (current_len > max_len) {
			max_len = current_len;
			number = i;
		}
	}
	*maxlen = max_len;
	return number;
}
