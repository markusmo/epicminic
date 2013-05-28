int main() {
	int a;
	int b;
	int c[100], d[100];

	c[a]=c[a+1]+d[b+2];

	a = a + b;
	a = a - b;
	a = a / b;
	a = a * b;
	a = (a + b);
	a = (a - b);
	a = -a;
	a = -b;
	a = -a + b;
	a = -a / b;
	a = (-a) / b;
	a = (-a / b);
	a = (a / -b);
	a = -a - -b;
	a = (-a) - (-b);
	a = -a - (-b);
	a = ((-a + b));
	a = ((-a)) / (-b);
	a = (-a * -a) / b;
	a = a + b - b;
	a = a + b / b;
	a = a + (b * a) / a;
	a = (a + ((b * -a) / a) + -b);
	a = (b + (b - -a) * a + -a);

	return 0;
}
