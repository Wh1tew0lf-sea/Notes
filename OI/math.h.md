# 目录

1、三角函数

2、双曲函数

3、指数函数与对数函数

4、幂函数

5、误差与伽马函数

6、四舍五入与余数函数

7、绝对值、最小、最大 Absolute、Minimum, maximum

C语言中的数学函数库是math.h，它提供了许多常用的数学函数，如三角函数、指数函数、对数函数、幂函数、取整函数等等。



下面是math.h中一些常用的函数及其用法：

## 1、三角函数

sin(x)：计算正弦函数的值，x为弧度制的角度。

cos(x)：计算余弦函数的值，x为弧度制的角度。

tan(x)：计算正切函数的值，x为弧度制的角度。

acos() 反余弦函数

asin() 反正弦函数

atan() 反正切函数

atan2() 带两个参数的反正切函数

#include <math.h>
#include <stdio.h>

int main()
{
    double angle = 30.0;
    double radian = angle * M_PI / 180.0;
    double result = sin(radian);
    printf("sin(%lf) = %lf\n", angle, result);
    return 0;
}

## 2、双曲函数

双曲余弦函数cosh()

双曲正弦函数sinh()

双曲正切函数tanh()

/* tanh example */
#include <stdio.h>      /* printf */
#include <math.h>       /* tanh, log */

int main ()
{
  double param, result;
  param = log(2.0);
  result = tanh (param);
  printf ("The hyperbolic tangent of %f is %f.\n", param, result);
  return 0;
}

## 3、指数函数与对数函数

exp () 指数函数，以 e 为底数

frexp(param，n) 二进制浮点数表示方法 x=param*2^n

log(x) x的自然对数 (Natural logarithm of x)

log10() 常用对数，以10为底 ( Common logarithm of x )

modf() 返回x的小数部分，其符号与x相同 ，但是参数中可以添加整数部分的变量( The fractional part of x, with the same sign)

exp2() 返回2的x次方，2 raised to the power of x.

log2() x的二进制对数( The binary logarithm of x)

/* log2 example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log2 */

int main ()
{
  double param, result;
  param = 1024.0;
  result = log2 (param);
  printf ("log2 (%f) = %f.\n", param, result );
  return 0;
}

## 4、幂函数

pow(base, power) 幂函数 The result of raising base to the power exponent

sqrt(x) 计算x的平方根

cbrt(x) 计算x的立方根

hypot(x,y) 计算直角三角形的斜边 ( The square root of (x^2+y^2) )

/* hypot example */
#include <stdio.h>      /* printf */
#include <math.h>       /* hypot */

int main ()
{
  double leg_x, leg_y, result;
  leg_x = 3;
  leg_y = 4;
  result = hypot (leg_x, leg_y);
  printf ("%f, %f and %f form a right-angled triangle.\n",leg_x,leg_y,result);
  return 0;
}

## 5、误差与伽马函数

误差函数erf(x)

余差函数erfc(x) erfc(x) = 1-erf(x) 误差函数的补函数

tgamma(x) 伽马函数 ( the gamma function )

lgamma(x) log伽马函数 ( log-gamma function )

/* lgamma example */
#include <stdio.h>      /* printf */
#include <math.h>       /* lgamma */

int main ()
{
  double param, result;
  param = 0.5;
  result = lgamma (param);
  printf ("lgamma(%f) = %f\n", param, result );
  return 0;
}

## 6、**四舍五入与余数函数**

**ceil(x) x上取整函数**

**floor(x) x的下取整函数**

fmod(y, x) y/x的余数

**round(x) x的四舍五入值**

/* round vs floor vs ceil vs trunc */
#include <stdio.h>      /* printf */
#include <math.h>       /* round, floor, ceil, trunc */

int main ()
{
  const char * format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
  printf ("value\tround\tfloor\tceil\ttrunc\n");
  printf ("-----\t-----\t-----\t----\t-----\n");
  printf (format, 2.3,round( 2.3),floor( 2.3),ceil( 2.3),trunc( 2.3));
  printf (format, 3.8,round( 3.8),floor( 3.8),ceil( 3.8),trunc( 3.8));
  printf (format, 5.5,round( 5.5),floor( 5.5),ceil( 5.5),trunc( 5.5));
  printf (format,-2.3,round(-2.3),floor(-2.3),ceil(-2.3),trunc(-2.3));
  printf (format,-3.8,round(-3.8),floor(-3.8),ceil(-3.8),trunc(-3.8));
  printf (format,-5.5,round(-5.5),floor(-5.5),ceil(-5.5),trunc(-5.5));
  return 0;
}

## 7、绝对值、最小、最大 Absolute、Minimum, maximum

fabs(x) x的绝对值函数

abs(x) x的绝对值

fmax(x, y) 两个参数中的最大值 (The maximum numeric value of its arguments. Values among which the function selects a maximum )

fmin(x, y) 两个参数中的最小值

/* fmin example */
#include <stdio.h>      /* printf */
#include <math.h>       /* fmin */

int main ()
{
  printf ("fmin (100.0, 1.0) = %f\n", fmin(100.0,1.0));
  printf ("fmin (-100.0, 1.0) = %f\n", fmin(-100.0,1.0));
  printf ("fmin (-100.0, -1.0) = %f\n", fmin(-100.0,-1.0));
  return 0;
}
当然，上面只列举了部分常用的函数，更多的内容，可以在需要的时候查阅相关手册。