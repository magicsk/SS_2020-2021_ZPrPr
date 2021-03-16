// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int intersection(
    double *pax, double *pay,
    double *pbx, double *pby,
    double *pcx, double *pcy,
    double *pdx, double *pdy) {

    double a1 = *pay - *pby;
    double a2 = *pcy - *pdy;
    double b1 = *pbx - *pax;
    double b2 = *pdx - *pcx;
    double c1 = (*pax * *pby) - (*pay * *pbx);
    double c2 = (*pcx * *pdy) - (*pcy * *pdx);

    double determinant = (a1 * b2) - (b1 * a2);
    if (determinant) {
        double intersectionX = ((b1 * c2) - (c1 * b2)) / determinant;
        double intersectionY = ((c1 * a2) - (a1 * c2)) / determinant;

        printf("Coordinates of lines intersection are (%.1lf, %.1lf)\n", intersectionX, intersectionY);

        return 1;
    } else {
        return 0;
    }
}

int main() {
    double ax, ay, bx, by, cx, cy, dx, dy;
    double *pax = &ax,
           *pay = &ay,
           *pbx = &bx,
           *pby = &by,
           *pcx = &cx,
           *pcy = &cy,
           *pdx = &dx,
           *pdy = &dy;

    printf("Enter coordinates of points A, B, C and D:\n");
    scanf("%lf %lf", &ax, &ay);
    scanf("%lf %lf", &bx, &by);
    scanf("%lf %lf", &cx, &cy);
    scanf("%lf %lf", &dx, &dy);

    if (!intersection(pax, pay, pbx, pby, pcx, pcy, pdx, pdy)) {
        printf("Lines AB and CD are parallel.\n");
    }
    return 0;
}