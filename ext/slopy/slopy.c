#include <ruby.h>
#include <math.h>


VALUE Slopy = Qnil;

void Init_slopy();

VALUE method_slopy_cos(VALUE self, VALUE vector1, VALUE vector2);

void Init_slopy() {
  Slopy = rb_define_class("Slopy", rb_cObject);
  rb_define_method(Slopy, "cos", method_slopy_cos, 2);
}


VALUE method_slopy_cos(VALUE self, VALUE vector1, VALUE vector2) {
  int v1_length = RARRAY_LEN(vector1);
  int v2_length = RARRAY_LEN(vector2);
  int dot_product = 0;
  int magnitude1 = 0;
  int magnitude2 = 0;
  int v1;
  int v2;
  
  for (int i = 0; i < v1_length; i++) {
    v1 = NUM2INT(rb_ary_entry(vector1, i));
    v2 = NUM2INT(rb_ary_entry(vector2, i));
    dot_product += (v1*v2);
    magnitude1 += (v1*v1);
    magnitude2 += (v2*v2);    
  }
  // double similarity = dotp(vector1, vector2) / (magnitude(vector1) * magnitude(vector2));
  double similarity = dot_product /(sqrt(magnitude1)* sqrt(magnitude2));
  return rb_float_new(similarity);
}


// int dotp(int vector1[], int vector2[]) {
//   int dotProduct = 0;
//   int arraysize = sizeof(vector1) / sizeof(vector1[0]);
//     for(int i = 0; i < arraysize; i++){
//     dotProduct += (vector1[i] * vector2[i]);
//   }
//   return dotProduct; 
// }
// 
// double magnitude(int vector[]) {
//   int magnitude = 0;
//   for(int i = 0; i < vector.length; i++){
//     int val = vector[i];
//     magnitude += val*val;
//   }
//   return sqrt(magnitude);
// }


