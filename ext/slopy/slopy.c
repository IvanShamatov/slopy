#include <ruby.h>
#include <math.h>


// Interface
VALUE Slopy = Qnil;
VALUE Calculator = Qnil;
void Init_slopy();
VALUE method_slopy_cos(VALUE self, VALUE vector1, VALUE vector2);
VALUE method_slopy_matrix(VALUE self, VALUE matrix);



void Init_slopy() {
  Slopy = rb_define_module("Slopy");
  Calculator = rb_define_module_under(Slopy, "Calculator");
  rb_define_singleton_method(Calculator, "cos", method_slopy_cos, 2);
  rb_define_singleton_method(Calculator, "matrix", method_slopy_matrix, 1);
}



VALUE method_slopy_cos(VALUE self, VALUE vector1, VALUE vector2) {
  int v1_length = RARRAY_LEN(vector1);
  int v2_length = RARRAY_LEN(vector2);
  if (v1_length != v2_length) {
    return false;
  }
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
  double similarity = dot_product /(sqrt(magnitude1)* sqrt(magnitude2));
  return rb_float_new(similarity);
}


VALUE method_slopy_matrix(VALUE self, VALUE vectors) {
  double matrix;
  return matrix;
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


