typedef long long LL;

LL rounding(double a) {
	LL b;
	if (a > 0) {
		b = (a * 2 + 1) / 2;
	}
	else {
		b = (a * 2 - 1) / 2;
	}
	return b;
}