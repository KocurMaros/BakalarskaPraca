#include <iostream>

COLOUR GetColour(double v,double vmin,double vmax){
 //When RGB color should be return
    if(grayColor==false)
    {
        if(vmin<vmax)
        {
            COLOUR c = {1.0,1.0,1.0}; // white
            double dv;

            if (v < vmin)
            v = vmin;
            if (v > vmax)
            v = vmax;
            dv = vmax - vmin;

            if (v < (vmin + 0.25 * dv)) {
                c.r = 0;
                c.g = 4 * (v - vmin) / dv;
            } else if (v < (vmin + 0.5 * dv)) {
                c.r = 0;
                c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
            } else if (v < (vmin + 0.75 * dv)) {
                c.r = 4 * (v - vmin - 0.5 * dv) / dv;
                c.b = 0;
            } else {
                c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
                c.b = 0;
            }
            return(c);
        }
        else
        {
            COLOUR c = {1.0,1.0,1.0}; // white
            double dv;
            dv=vmin;
            vmin=vmax;
            vmax=dv;
            if (v < vmin)
                v = vmin;
            if (v > vmax)
                v = vmax;
            dv = vmax - vmin;
            v=vmax-v;
            if (v < (vmin + 0.25 * dv)) {
                c.r = 0;
                c.g = 4 * (v - vmin) / dv;
            } else if (v < (vmin + 0.5 * dv)) {
                c.r = 0;
                c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
            } else if (v < (vmin + 0.75 * dv)) {
                c.r = 4 * (v - vmin - 0.5 * dv) / dv;
                c.b = 0;
            } else {
                c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
                c.b = 0;
            }

            return(c);
        }
    }
    //When gray color should be return
    if (v < vmin)
        v = vmin;
    if (v > vmax)
        v = vmax;
    COLOUR c;
    c.r=(v-vmin)/(vmax-vmin);
    c.g=(v-vmin)/(vmax-vmin);
    c.b=(v-vmin)/(vmax-vmin);
    return c;
 }

int main(){




    return 0;
}