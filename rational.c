#include <stdio.h>
#include <stdlib.h>

struct rational 
{
    int moleclules;
    int denominator;
};

struct rational make_rational(int m, int d)
{
    struct rational z;

    z.moleclules = m;
    z.denominator = d;
   
    return z;
}

int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    else
        return (gcd(b, a%b));
}

struct rational add_rational(struct rational a, struct rational b)
{
    struct rational z;
    int greatest;
   
    greatest = gcd(abs(a.denominator), b.denominator);
    z.moleclules = a.moleclules*b.denominator/greatest + b.moleclules*a.denominator/greatest;
    z.denominator = a.denominator*b.denominator/greatest;
    if(z.moleclules != 0)
    {
        greatest = gcd(abs(z.moleclules), z.denominator);
        z.moleclules = z.moleclules/greatest;
        z.denominator = z.denominator/greatest;
    }

    return z;
}
struct rational sub_rational(struct rational a, struct rational b)
{
    struct rational z;
    int greatest;
   
    greatest = gcd(abs(a.denominator), b.denominator);
    z.moleclules = a.moleclules*b.denominator/greatest - b.moleclules*a.denominator/greatest;
    z.denominator = a.denominator*b.denominator/greatest;
    if(z.moleclules != 0)
    {
        greatest = gcd(abs(z.moleclules), z.denominator);
        z.moleclules = z.moleclules/greatest;
        z.denominator = z.denominator/greatest;
    }

    return z;
}

struct rational mul_rational(struct rational a, struct rational b)
{
    struct rational z;
    int greatest;

    z.moleclules = a.moleclules * b.moleclules;
    z.denominator = a.denominator * b.denominator;
    greatest = gcd(abs(z.moleclules), z.denominator);
    z.moleclules = z.moleclules/greatest;
    z.denominator = z.denominator/greatest;

    return z;
}


struct rational div_rational(struct rational a, struct rational b)
{
    struct rational z;
    int greatest;

    z.moleclules = a.moleclules * b.denominator;
    z.denominator = a.denominator + b.moleclules;
    greatest = gcd(abs(z.moleclules), z.denominator);
    z.moleclules = z.moleclules/greatest;
    z.denominator = z.denominator/greatest;

    return z;
}

void printf_ration(struct rational z)
{
    if(z.moleclules != 0)
        printf("result is :%d/%d\n", z.moleclules, z.denominator);
    else
        printf("result is :0\n");
    return;
}

int main(int argc, const char *argv[])
{
    struct rational a = make_rational(1, 8);
    struct rational b = make_rational(-1, 8);

    printf_ration(add_rational(a, b));
    printf_ration(sub_rational(a, b));
    printf_ration(mul_rational(a, b));
    printf_ration(div_rational(a, b));

    return 0;
}
