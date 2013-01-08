struct angle {
  angle(long double r): radians(r) {}
  long double radians;
};


Now we have a problem: this structure is built using an angle expressed in radians, not degrees:

long double radians = 2.0;
long double degrees = 90.0;

angle r(radians); // fine
angle d(degrees); // oups!


As-is, we cannot build the angle using degrees (worse: it will compile) that easily. That's an example where a user-defined literal is useful:

angle operator "" _deg(long double degrees) {
  static long double const pi = atan(1.0) * 4.0; 
    return angle(degrees * pi / 180.0);
}


Now, we can define a cosinus function taking radians, and use it with degrees as well:

long double cosinus(angle const& a) {
  return cos(a.radians); 
}

std::cout << cosinus(60.0_deg) << std::endl; // degrees
std::cout << cosinus(1.0) << std::endl; // radians


The output is correct:

0.5
0.540302 

