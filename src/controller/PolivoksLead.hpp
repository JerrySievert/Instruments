#pragma once

#include <cstdint>

#include "../Instruments.hpp"

struct PolivoksLeadContainer {
  float *sample;
  unsigned int length;
  int current;
};

struct PolivoksLeadModule : Module {
  enum ParamIds { NUM_PARAMS };
  enum InputIds { NOTE1_INPUT, NUM_INPUTS };
  enum OutputIds { AUDIO1_OUTPUT, NUM_OUTPUTS };
  enum LightIds { NUM_LIGHTS };

  PolivoksLeadModule( );
  void step( ) override;

  uint32_t currentStep;
  int last;
};
