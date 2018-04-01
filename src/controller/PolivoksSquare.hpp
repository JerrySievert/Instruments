#pragma once

#include <cstdint>

#include "../Instruments.hpp"

struct PolivoksSquareContainer {
  float *sample;
  unsigned int length;
  int current;
};

struct PolivoksSquareModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds { NOTE1_INPUT, NUM_INPUTS };
  enum OutputIds { AUDIO1_OUTPUT, NUM_OUTPUTS };
  enum LightIds { NUM_LIGHTS };

  PolivoksSquareModule( );
  void step( ) override;

  uint32_t currentStep;
  int last;
};
