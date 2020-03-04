#include <stdio.h>
#include <math.h>

struct complex_struct {
	double x, y;
};

double real_part(struct complex_struct z) {
	return z.x;
}

double img_part(struct complex_struct z) {
	return z.y;
}

double magnitude(struct complex_struct z) {
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z) {
	return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y) {
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A) {
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_real_img(real_part(z1) + real_part(z2),  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_real_img(real_part(z1) - real_part(z2),  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void print_complex_by_real_img(struct complex_struct z) {
	if (real_part(z) == 0)
	  printf("%fi", img_part(z));
	else if (img_part(z) == 0)
	  printf("%f", real_part(z));
	else 
		printf("%f + %fi", real_part(z), img_part(z));
}

int main(void) {
	struct complex_struct z1 = {1.0, 2.0};
	struct complex_struct z2 = {2.0, 3.0};
	struct complex_struct z = mul_complex(z1, z2);
	printf("%f%f\n", z.x, z.y);
	print_complex_by_real_img(div_complex(z1, z2));	
	return 0;
}
