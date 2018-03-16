#include "PolivoksLead.hpp"
#include "../samples/lead.h"

static struct PolivoksLeadContainer leadsamples[ 36 ] = {
  { (float *) leadc3,  leadc3_len,  0 },
  { (float *) leadcs3, leadcs3_len, 1 },
  { (float *) leadd3,  leadd3_len,  2 },
  { (float *) leadds3, leadds3_len, 3 },
  { (float *) leade3,  leade3_len,  4 },
  { (float *) leadf3,  leadf3_len,  5 },
  { (float *) leadfs3, leadfs3_len, 6 },
  { (float *) leadg3,  leadg3_len,  7 },
  { (float *) leadgs3, leadgs3_len, 8 },
  { (float *) leada3,  leada3_len,  9 },
  { (float *) leadas3, leadas3_len, 10 },
  { (float *) leadb3,  leadb3_len,  11 },
  { (float *) leadc4,  leadc4_len,  12 },
  { (float *) leadcs4, leadcs4_len, 13 },
  { (float *) leadd4,  leadd4_len,  14 },
  { (float *) leadds4, leadds4_len, 15 },
  { (float *) leade4,  leade4_len,  16 },
  { (float *) leadf4,  leadf4_len,  17 },
  { (float *) leadfs4, leadfs4_len, 18 },
  { (float *) leadg4,  leadg4_len,  19 },
  { (float *) leadgs4, leadgs4_len, 20 },
  { (float *) leada4,  leada4_len,  21 },
  { (float *) leadas4, leadas4_len, 22 },
  { (float *) leadb4,  leadb4_len,  23 },
  { (float *) leadc5,  leadc5_len,  24 },
  { (float *) leadcs5, leadcs5_len, 25 },
  { (float *) leadd5,  leadd5_len,  26 },
  { (float *) leadds5, leadds5_len, 27 },
  { (float *) leade5,  leade5_len,  28 },
  { (float *) leadf5,  leadf5_len,  29 },
  { (float *) leadfs5, leadfs5_len, 30 },
  { (float *) leadg5,  leadg5_len,  31 },
  { (float *) leadgs5, leadgs5_len, 32 },
  { (float *) leada5,  leada5_len,  33 },
  { (float *) leadas5, leadas5_len, 34 },
  { (float *) leadb5,  leadb5_len,  35 }
};

static float leadnotes[36] = {
  -2, -1.92, -1.83, -1.75, -1.67, -1.58, -1.5, -1.42, -1.33, -1.25, -1.17, -1.08,
  -1, -0.92, -0.83, -0.75, -0.67, -0.58, -0.5, -0.42, -0.33, -0.25, -0.17, -0.08,
  0, 0.08, 0.17, 0.25, 0.33, 0.42, 0.5, 0.58, 0.67, 0.75, 0.83, 0.92
};

static struct PolivoksLeadContainer *leadGetNote(float current) {
  for (int i = 0; i < 36; i++) {
    if ((leadnotes[i] - 0.02) <= current && (leadnotes[i] + 0.02) >= current) {
      return &leadsamples[i];
    }
  }

  return NULL;
}

PolivoksLeadModule::PolivoksLeadModule( ) : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
  currentStep = 0;
  last = -1;
}

void PolivoksLeadModule::step( ) {
  float in1 = inputs[ NOTE1_INPUT ].value;
  struct PolivoksLeadContainer *note;

  // check the first note
  note = leadGetNote(in1);

  if (note == NULL) {
    currentStep = 0;
    outputs[ AUDIO1_OUTPUT ].value = 0;
    last = -1;
  } else {
    if (last != note->current) {
      last = note->current;
      currentStep = 0;
    }

    if (currentStep == note->length) {
      currentStep = 0;
    }

    outputs[ AUDIO1_OUTPUT ].value = note->sample[currentStep];
    currentStep++;
  }
}
