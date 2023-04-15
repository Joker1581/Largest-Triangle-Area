#include <stdio.h>
#include <stdlib.h>

double getDis(int* pointA, int* pointB)
{
    return(sqrt(pow(pointA[0] - pointB[0], 2) + pow(pointA[1] - pointB[1], 2)));
}

double getArea(int* pointA, int* pointB, int* pointC)
{
    double a, b, c, s;
    a = getDis(pointA, pointB);
    b = getDis(pointB, pointC);
    c = getDis(pointA, pointC);
    s = (a+b+c)/2;
    
    return(sqrt(s*(s-a)*(s-b)*(s-c)));
}

double largestTriangleArea(int** points, int pointsRowSize, int *pointsColSizes) {
    double area, ans = 0;
    for(int i = 0; i < pointsRowSize - 2; i++)
    {
        for(int j = i+1; j < pointsRowSize -1; j++)
        {
            for(int k = j+1; k < pointsRowSize; k++)
            {
                area = getArea(points[i], points[j], points[k]);
                //printf("%f\n", area);
                if(area > ans) ans = area;
            }
        }
    }
    return ans;
}