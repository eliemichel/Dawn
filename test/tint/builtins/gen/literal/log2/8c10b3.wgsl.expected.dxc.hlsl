void log2_8c10b3() {
  float16_t res = log2(float16_t(0.0h));
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  log2_8c10b3();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  log2_8c10b3();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  log2_8c10b3();
  return;
}