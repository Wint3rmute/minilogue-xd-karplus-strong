#include <math.h>
#include <stdlib.h>
#include <userosc.h>
#include <utils/fixed_math.h>

float phase = 0.0;
float phase_change = 0.0;

#define ARRAY_SIZE 6000

float array[ARRAY_SIZE] = {0};
int array_index = 0;
int max_array = 100;

float feedback = 0.5;
float one_minus_feedback = 0.5;

void array_fill() {
  for (int i = 0; i < max_array; i++) {
    array[i] = (float)rand() / (float)(RAND_MAX / 2.0) - 1;
  }
}

void OSC_INIT(uint32_t platform, uint32_t api) { array_fill(); }

void OSC_CYCLE(const user_osc_param_t *const params, int32_t *yn,
               const uint32_t frames) {

  for (uint32_t i = 0; i < frames; i++) {
    float signal = array[array_index];
    array_index++;

    if (array_index >= max_array) {
      array_index = 0;
    }

    array[array_index] =
        feedback * array[array_index] + one_minus_feedback * signal;

    *yn = f32_to_q31(signal);
    yn++;
  }
}

void OSC_NOTEON(const user_osc_param_t *const params) {
  array_index = 0;
  max_array = k_samplerate / osc_notehzf(params->pitch >> 8);
  array_fill();
}

void OSC_NOTEOFF(const user_osc_param_t *const params) {}

void OSC_PARAM(uint16_t index, uint16_t value) {
  switch (index) {
  case k_user_osc_param_shape:
    feedback = param_val_to_f32(value);
    one_minus_feedback = 1.0 - feedback;
    break;

  default:
    break;
  }
}
